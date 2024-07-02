.globl factorial

.data
n: .word 8

.text
main:
    la t0, n
    lw a0, 0(t0)
    jal ra, factorial

    addi a1, a0, 0
    addi a0, x0, 1
    ecall # Print Result

    addi a1, x0, '\n'
    addi a0, x0, 11
    ecall # Print newline

    addi a0, x0, 10
    ecall # Exit

factorial:
    # YOUR CODE HERE
    addi sp, sp, -8
    sw a0, 4(sp)
    sw ra, 0(sp)
    addi t0, x0,1
    bgt a0, t0, else
    addi a0, x0,1
    addi sp, sp,8
    jr ra
else:
    addi a0, a0, -1
    jal factorial
    lw t1, 4(sp)
    lw ra, 0(sp)
    addi sp, sp, 8
    mul a0, t1, a0
    jr ra
   

    
    
    
