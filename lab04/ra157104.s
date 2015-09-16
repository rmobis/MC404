.text					@ seção de código
	.align 4			@ alinha ponto de montagem em endereços múltiplos de 4
	.globl main			@ torna o símbolo main visivel fora do arquivo
	.globl _start		@ torna o símbolo _start visivel fora do arquivo

_start:
main:
	mov r0, #1			@ carrega o valor 1 em r0, indicando que a saída da
						@ syscall write sera em stdout
	ldr r1, =string		@ carrega em r1 o endereco da string
	mov r2, #19			@ carrega em r2 o tamanho da string. r0,r1 e r2 serão
						@ os argumentos da syscall write
	mov r7, #4			@ carrega o valor 4 para r7, indica o tipo da syscall
	svc 0x0				@ realiza uma chamada de sistema (syscall)
	mov r7, #19			@ carrega o valor 1 em r7, indicando a escolha da
						@ syscall exit
	svc 0x0

.data					@ seção de dados

string:  .asciz "Raphael - ra157104\n"	@coloca a string na memoria
