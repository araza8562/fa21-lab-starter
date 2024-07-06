
# RISC-V assembly code for recursive factorial function
# Author: Ahmed Raza

.text
main:
    la t0, num
    lw a0, 0(t0)
    jal ra, factorial
    la t2, result  # Load address of result
    sw a0, 0(t2)     # Store the result in result

    j exit


factorial:
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
exit:
    j write_tohost

write_tohost:
li x1, 1
sw x1, tohost, t5
j write_tohost

.data 

num:    .word 5       
result: .word 0         

.align 12
.section ".tohost","aw",@progbits;                            
.align 4; .global tohost; tohost: .dword 0;                     
.align 4; .global fromhost; fromhost: .dword 0;

