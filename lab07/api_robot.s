@@
@ Description: Uoli Robot Application Programming Implementation.
@
@ Author: Raphael Mobis Tacla (r.mobis@gmail.com)
@
@ Date: 2015
@@

	@ Make functions global
	.global set_speed_motor
	.global set_speed_motors
	.global read_sonar
	.global read_sonars

	.align 4


@@
@ Sets motor speed.
@ Parameters:
@   speed: the motor speed (Only the last 6 bits are used)
@   id: the motor id (0 for left motor, 1 for right motor)
@ Returns:
@   void
@@
set_speed_motor:
	stmfd sp!, {r7}

	add   r7, r1, #126
	svc   0x0

	ldmfd sp!, {r7}
	bx    LR


@@
@ Sets both motors speed.
@ Parameters:
@   spd_m0: the speed of motor 0 (Only the last 6 bits are used)
@   spd_m1: the speed of motor 1 (Only the last 6 bits are used)
@ Returns:
@   void
@@
set_speed_motors:
	stmfd sp!, {r7, lr}

	mov   r7, #124
	svc   0x0

	ldmfd sp!, {r7, pc}


@@
@ Reads one of the sonars.
@ Parameter:
@   id: the sonar id (ranges from 0 to 15).
@ Returns:
@   the distance as an integer from 0 to (2^12)-1
@@
read_sonar:
	stmfd sp!, {r7, lr}

	mov   r7, #125
	svc   0x0

	ldmfd sp!, {r7, pc}


@@
@ Reads all sonars at once.
@ Parameter:
@   sonars: array of 16 unsigned integers. The distances are stored
@   on the array.
@ Returns:
@   void
@@
read_sonars:
	stmfd sp!, {lr}

	mov r2, r0
	mov r1, #0

rss_loop:
	mov r0, r1
	bl  read_sonar

	stmfa r2!, {r0}

	add r1, r1, #1
	cmp r1, #16
	bne rss_loop

	ldmfd sp!, {pc}
