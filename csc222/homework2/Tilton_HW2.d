
Tilton_HW2.o:     file format elf64-x86-64


Disassembly of section .text:

0000000000000000 <_Z10addbyvaluell>:
   0:	48 8d 04 37          	lea    (%rdi,%rsi,1),%rax
   4:	c3                   	retq   

0000000000000005 <_Z14addbyreferencellPl>:
   5:	48 01 fe             	add    %rdi,%rsi
   8:	48 89 32             	mov    %rsi,(%rdx)
   b:	c3                   	retq   

000000000000000c <main>:
   c:	55                   	push   %rbp
   d:	53                   	push   %rbx
   e:	48 83 ec 18          	sub    $0x18,%rsp
  12:	48 89 f5             	mov    %rsi,%rbp
  15:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
  1c:	00 00 
  1e:	48 89 44 24 08       	mov    %rax,0x8(%rsp)
  23:	31 c0                	xor    %eax,%eax
  25:	48 8b 7e 08          	mov    0x8(%rsi),%rdi
  29:	ba 0a 00 00 00       	mov    $0xa,%edx
  2e:	be 00 00 00 00       	mov    $0x0,%esi
  33:	e8 00 00 00 00       	callq  38 <main+0x2c>
  38:	48 63 d8             	movslq %eax,%rbx
  3b:	48 8b 7d 10          	mov    0x10(%rbp),%rdi
  3f:	ba 0a 00 00 00       	mov    $0xa,%edx
  44:	be 00 00 00 00       	mov    $0x0,%esi
  49:	e8 00 00 00 00       	callq  4e <main+0x42>
  4e:	48 63 e8             	movslq %eax,%rbp
  51:	48 89 ee             	mov    %rbp,%rsi
  54:	48 89 df             	mov    %rbx,%rdi
  57:	e8 00 00 00 00       	callq  5c <main+0x50>
  5c:	49 89 c0             	mov    %rax,%r8
  5f:	48 89 e9             	mov    %rbp,%rcx
  62:	48 89 da             	mov    %rbx,%rdx
  65:	be 00 00 00 00       	mov    $0x0,%esi
  6a:	bf 01 00 00 00       	mov    $0x1,%edi
  6f:	b8 00 00 00 00       	mov    $0x0,%eax
  74:	e8 00 00 00 00       	callq  79 <main+0x6d>
  79:	48 c7 04 24 00 00 00 	movq   $0x0,(%rsp)
  80:	00 
  81:	48 89 e2             	mov    %rsp,%rdx
  84:	48 89 ee             	mov    %rbp,%rsi
  87:	48 89 df             	mov    %rbx,%rdi
  8a:	e8 00 00 00 00       	callq  8f <main+0x83>
  8f:	4c 8b 04 24          	mov    (%rsp),%r8
  93:	48 89 e9             	mov    %rbp,%rcx
  96:	48 89 da             	mov    %rbx,%rdx
  99:	be 00 00 00 00       	mov    $0x0,%esi
  9e:	bf 01 00 00 00       	mov    $0x1,%edi
  a3:	b8 00 00 00 00       	mov    $0x0,%eax
  a8:	e8 00 00 00 00       	callq  ad <main+0xa1>
  ad:	48 8b 4c 24 08       	mov    0x8(%rsp),%rcx
  b2:	64 48 33 0c 25 28 00 	xor    %fs:0x28,%rcx
  b9:	00 00 
  bb:	74 05                	je     c2 <main+0xb6>
  bd:	e8 00 00 00 00       	callq  c2 <main+0xb6>
  c2:	b8 00 00 00 00       	mov    $0x0,%eax
  c7:	48 83 c4 18          	add    $0x18,%rsp
  cb:	5b                   	pop    %rbx
  cc:	5d                   	pop    %rbp
  cd:	c3                   	retq   
