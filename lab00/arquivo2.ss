
arquivo2.o:     file format elf64-x86-64


Disassembly of section .text:

0000000000000000 <funcao>:
   0:	55                   	push   %rbp
   1:	48 89 e5             	mov    %rsp,%rbp
   4:	bf 00 00 00 00       	mov    $0x0,%edi
   9:	e8 00 00 00 00       	callq  e <funcao+0xe>
   e:	5d                   	pop    %rbp
   f:	c3                   	retq   

Disassembly of section .rodata:

0000000000000000 <.rodata>:
   0:	45 73 74             	rex.RB jae 77 <funcao+0x77>
   3:	6f                   	outsl  %ds:(%rsi),(%dx)
   4:	75 20                	jne    26 <funcao+0x26>
   6:	6e                   	outsb  %ds:(%rsi),(%dx)
   7:	6f                   	outsl  %ds:(%rsi),(%dx)
   8:	20 61 72             	and    %ah,0x72(%rcx)
   b:	71 75                	jno    82 <funcao+0x82>
   d:	69 76 6f 20 32 21 00 	imul   $0x213220,0x6f(%rsi),%esi

Disassembly of section .comment:

0000000000000000 <.comment>:
   0:	00 47 43             	add    %al,0x43(%rdi)
   3:	43 3a 20             	rex.XB cmp (%r8),%spl
   6:	28 47 4e             	sub    %al,0x4e(%rdi)
   9:	55                   	push   %rbp
   a:	29 20                	sub    %esp,(%rax)
   c:	34 2e                	xor    $0x2e,%al
   e:	39 2e                	cmp    %ebp,(%rsi)
  10:	32 20                	xor    (%rax),%ah
  12:	32 30                	xor    (%rax),%dh
  14:	31 34 31             	xor    %esi,(%rcx,%rsi,1)
  17:	31 30                	xor    %esi,(%rax)
  19:	31 20                	xor    %esp,(%rax)
  1b:	28 52 65             	sub    %dl,0x65(%rdx)
  1e:	64 20 48 61          	and    %cl,%fs:0x61(%rax)
  22:	74 20                	je     44 <funcao+0x44>
  24:	34 2e                	xor    $0x2e,%al
  26:	39 2e                	cmp    %ebp,(%rsi)
  28:	32                   	.byte 0x32
  29:	2d                   	.byte 0x2d
  2a:	31 29                	xor    %ebp,(%rcx)
	...

Disassembly of section .eh_frame:

0000000000000000 <.eh_frame>:
   0:	14 00                	adc    $0x0,%al
   2:	00 00                	add    %al,(%rax)
   4:	00 00                	add    %al,(%rax)
   6:	00 00                	add    %al,(%rax)
   8:	01 7a 52             	add    %edi,0x52(%rdx)
   b:	00 01                	add    %al,(%rcx)
   d:	78 10                	js     1f <.eh_frame+0x1f>
   f:	01 1b                	add    %ebx,(%rbx)
  11:	0c 07                	or     $0x7,%al
  13:	08 90 01 00 00 1c    	or     %dl,0x1c000001(%rax)
  19:	00 00                	add    %al,(%rax)
  1b:	00 1c 00             	add    %bl,(%rax,%rax,1)
  1e:	00 00                	add    %al,(%rax)
  20:	00 00                	add    %al,(%rax)
  22:	00 00                	add    %al,(%rax)
  24:	10 00                	adc    %al,(%rax)
  26:	00 00                	add    %al,(%rax)
  28:	00 41 0e             	add    %al,0xe(%rcx)
  2b:	10 86 02 43 0d 06    	adc    %al,0x60d4302(%rsi)
  31:	4b 0c 07             	rex.WXB or $0x7,%al
  34:	08 00                	or     %al,(%rax)
	...
