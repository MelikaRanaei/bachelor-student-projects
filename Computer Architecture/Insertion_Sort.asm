.text
	la $t0, n
	lw $s0, 0($t0)	#$s0 =n
	la $t1, array
	addi $t2, $zero, 1  #$t2 = i=1(counter)
	
	outerLoop:
		beq $t2, $s0, outerExit  #if $t2 == $s0 then goto outerExit
		sll $t7, $t2, 2		#$t7 = 4*i
		add $t7, $t7,$t1	#$t7 = $t7 + $t1 (4*i + $t1)
		lw $t3, 0($t7)		#$t3 = array[i] =value
		addi $t5, $t2, -1	#$t5 = $t2 - 1 (j = i - 1)
		
		innerLoop:
			slti $t6, $t5, 0		#if $t5 < 0 then $t6 = 1 else $t6 = 0
			bne $t6, $zero, innerExit	#if $t6 != 0 then goto innerExit
			
			sll $t7, $t5, 2			#$t7 =  4*j
			add $t7, $t7,$t1	
			lw $t4, 0($t7)			#$t4 = array[j]
			
			slt $t6, $t3, $t4 		#if value <A[j] 
			beq $t6, $zero, innerExit	#if $t6==0 goto innerExit
			sw $t4, 4($t7)			#array[j+1] = $t4
			addi $t5, $t5, -1		#$t5 = $t5 - 1 =j--
			
			j innerLoop
		innerExit:
		
		addi $t5,$t5,1  #j++
		sll $t5, $t5, 2	 #j*4
		add $t5, $t5,$t1  #$t1+j*4
		sw $t3,0($t5)   #A[j+1]=key
		addi $t2,$t2,1  #i++
		j outerLoop
		
	outerExit:
	


	
	#Exit 
	addi $v0, $zero, 10
	syscall
	
	
	
.data
n:	.word 9
array:	.word 5,6,8,10,-12,20,7,34,1	

