	.file	"Tilton_HW2.c"
	.text
	.globl	_Z10addbyvaluell
	.type	_Z10addbyvaluell, @function
_Z10addbyvaluell:
.LFB50:
	.cfi_startproc
	leaq	(%rdi,%rsi), %rax
	ret
	.cfi_endproc
.LFE50:
	.size	_Z10addbyvaluell, .-_Z10addbyvaluell
	.globl	_Z14addbyreferencellPl
	.type	_Z14addbyreferencellPl, @function
_Z14addbyreferencellPl:
.LFB51:
	.cfi_startproc
	addq	%rdi, %rsi
	movq	%rsi, (%rdx)
	ret
	.cfi_endproc
.LFE51:
	.size	_Z14addbyreferencellPl, .-_Z14addbyreferencellPl
	.section	.rodata.str1.8,"aMS",@progbits,1
	.align 8
.LC0:
	.string	"the sum of %ld and %ld = %ld \n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB52:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushq	%rbx
	.cfi_def_cfa_offset 24
	.cfi_offset 3, -24
	subq	$24, %rsp
	.cfi_def_cfa_offset 48
	movq	%rsi, %rbp
	movq	%fs:40, %rax
	movq	%rax, 8(%rsp)
	xorl	%eax, %eax
	movq	8(%rsi), %rdi
	movl	$10, %edx
	movl	$0, %esi
	call	strtol
	movslq	%eax, %rbx
	movq	16(%rbp), %rdi
	movl	$10, %edx
	movl	$0, %esi
	call	strtol
	movslq	%eax, %rbp
	movq	%rbp, %rsi
	movq	%rbx, %rdi
	call	_Z10addbyvaluell
	movq	%rax, %r8
	movq	%rbp, %rcx
	movq	%rbx, %rdx
	movl	$.LC0, %esi
	movl	$1, %edi
	movl	$0, %eax
	call	__printf_chk
	movq	$0, (%rsp)
	movq	%rsp, %rdx
	movq	%rbp, %rsi
	movq	%rbx, %rdi
	call	_Z14addbyreferencellPl
	movq	(%rsp), %r8
	movq	%rbp, %rcx
	movq	%rbx, %rdx
	movl	$.LC0, %esi
	movl	$1, %edi
	movl	$0, %eax
	call	__printf_chk
	movq	8(%rsp), %rcx
	xorq	%fs:40, %rcx
	je	.L4
	call	__stack_chk_fail
.L4:
	movl	$0, %eax
	addq	$24, %rsp
	.cfi_def_cfa_offset 24
	popq	%rbx
	.cfi_def_cfa_offset 16
	popq	%rbp
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE52:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.4) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
