.text
main:

	la $s3,n
	lw $a0,0($s3)
	jal	fib
	add 	$a0,$zero,$v0
	jal	print
	sw $a0,4($s3)
	j Exit

fib:
        addi	$sp, $sp, -12
	sw	$ra, 0($sp)
	sw	$s0, 4($sp)
	sw	$s1, 8($sp)

	addi	$s0, $a0, 0
	beq	$s0, $zero, done   #if s0==0 or no
	addi	$t0, $0, 1
	beq	$t0, $s0, done     #if $s0==1 or no

	addi	$a0, $s0, -1   #$s0-1
	jal	fib            #fib(n-1)
	addi	$s1, $v0, 0
	addi	$a0, $s0, -2   #$s0-2
	jal	fib	       #fib(n-2)
	add	$v0, $v0, $s1  #fib(n-1)+fib(n-2)

	lw	$s1, 8($sp)
	lw	$s0, 4($sp)
	lw	$ra, 0($sp)
	addi	$sp, $sp, 12
	jr	$ra




done:
        add	$v0, $0, $s0
	lw	$s1, 8($sp)
	lw	$s0, 4($sp)
	lw	$ra, 0($sp)
	addi	$sp, $sp, 12
	jr	$ra



print:

	add	$a0, $v0,$zero
	addi	$v0,,$0, 1
	syscall
	jr	$ra






#Exit
Exit:
   addi $v0, $zero, 10
   syscall


.data
n:	.word 7   #x0=0,x1=1,x2=1,x3=2,x4=3,x5=5,x6=8,x7=13
