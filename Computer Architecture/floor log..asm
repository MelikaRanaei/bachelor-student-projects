 .text 
 
 	#print message:
	la $a0, msg	
       	addi $v0, $zero,4
        syscall   


	#read integer:
        addi $v0, $zero,5
        syscall

        add $t1, $v0, $zero	# $s0 = $v0 + $zero
        addi $t0, $t0, 0

loop:   

        beq $t1, $zero, exitloop  #if $t1==0 
	srl $t1, $t1, 1
        addi $t0 , $t0, 1  
        j loop

exitloop:
	
	
	#print result:
	la $a0, result
        addi $v0, $zero,4
        syscall


	addi $t0, $t0, -1
        addi $v0, $zero,1  #print integer
        add $a0,$zero, $t0
        syscall

#Exit
addi $v0,$zero,10
syscall


.data

msg:   .asciiz "Enter x : "
result:     .asciiz "Result = "

 
       
             
                         
