.comm	x,4,4
.globl	foo
foo:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$0,%esp
	movl	$1,%eax
	movl	%eax,x
	movl	$2,%eax
	movl	%eax,y
	movl	$3,%eax
	movl	%eax,z
	movl	%ebp,%esp
	popl	%ebp
	ret

