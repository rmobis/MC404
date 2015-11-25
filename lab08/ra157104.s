.set GPT_BASE,       0x53FA0000
.set GPT_CR,         0x00
.set GPT_PR,         0x04
.set GPT_SR,         0x08
.set GPT_IR,         0x0C
.set GPT_OCR1,       0x10

.set TZIC_BASE,      0x0FFFC000
.set TZIC_INTCTRL,   0x0
.set TZIC_INTSEC1,   0x84
.set TZIC_ENSET1,    0x104
.set TZIC_PRIOMASK,  0xC
.set TZIC_PRIORITY9, 0x424

.set TIME_SZ,        0x100


.org 0x0
.section .iv, "a"

.align 4
_start:

interrupt_vector:
	b reset_handler

.org 0x08
	b syscall_handler

.org 0x18
	b irq_handler

.org 0x100
.text

@     ____  ___________ ____________   __  _____    _   ______  __    __________
@    / __ \/ ____/ ___// ____/_  __/  / / / /   |  / | / / __ \/ /   / ____/ __ \
@   / /_/ / __/  \__ \/ __/   / /    / /_/ / /| | /  |/ / / / / /   / __/ / /_/ /
@  / _, _/ /___ ___/ / /___  / /    / __  / ___ |/ /|  / /_/ / /___/ /___/ _, _/
@ /_/ |_/_____//____/_____/ /_/    /_/ /_/_/  |_/_/ |_/_____/_____/_____/_/ |_|
@
reset_handler:
	@ Sets the start address of the interrupt vector on the co-processor
	ldr r0, =interrupt_vector
	mcr p15, 0, r0, c12, c0, 0


	@ Resets the ticks counter
	ldr r2, =ticks
	mov r0, #0
	str r0, [r2]


	@ Configuring GPTIO
	ldr r0, =GPT_BASE

	@ Enables GPT, specifically on Stop and Wait modes
	mov r1, #0x41
	str r1, [r0, #GPT_CR]

	@ Sets the scale to 1
	mov r1, #0
	str r1, [r0, #GPT_PR]

	@ Enables the Output Control Channel 1
	mov r1, #1
	str r1, [r0, #GPT_IR]

	@ Sets the interval for the interruption
	ldr r1, =TIME_SZ
	str r1,	[r0, #GPT_OCR1]


	@ Configuring TZIC
	ldr r0, =TZIC_BASE

	@ Sets GPT interruption as non-secure
	mov r1, #(1 << 7)
	str r1, [r0, #TZIC_INTSEC1]

	@ Enables GPT interruption
	mov r1, #(1 << 7)
	str r1, [r0, #TZIC_ENSET1]

	@ Sets the interrupt priority to 1 (0 is highest)
	ldr r1, [r0, #TZIC_PRIORITY9]
	bic r1, r1, #0xFF000000        @ Clears the first 8 bits
	mov r2, #1
	orr r1, r1, r2, lsl #24        @ Sets the bit 7 to 1
	str r1, [r0, #TZIC_PRIORITY9]

	@ Zeroes the priority mask
	mov r1, #0
	str r1, [r0, #TZIC_PRIOMASK]

	@ Enables interruptions
	mov r1, #1
	str r1, [r0, #TZIC_INTCTRL]

	@ Supervisor mode; IRQ/FIQ enabled
	msr CPSR_c, #0x13

laco_infinito:
	b laco_infinito



syscall_handler:
	sub r7, r7, #16
	add pc, pc, r7



irq_handler:
	ldr r0, =GPT_BASE

	@ Marks the interruption as handled
	mov r1, #0x1
	str r1, [r0, #GPT_SR]

	@ Increases the tick count
	ldr r0, =ticks
	ldr r1, [r0]
	add r1, r1, #1
	str r1, [r0]

	@ Branches back to the code
	sub lr, lr, #8
	movs pc, lr

.data

ticks: .word 0
