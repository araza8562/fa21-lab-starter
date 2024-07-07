# Author: Ahmed Raza
# Description: This RISC-V assembly code tests five versions of the accumulator function using different input arrays. Each version of the accumulator function should return the sum of the elements of the input array. If a test passes, it prints "Test Passed!", otherwise, it prints "Test Failed!".

.import lotsofaccumulators.s

.data
inputarray: .word 1,2,3,4,5,6,7,0        #Pass for every accumulators
inputarray1: .word 0,1,2,3,4,5,6,7,0         #Pass test for accumulator 5 and fail for other accumulators
inputarray2:  .word 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0
inputarray3: .word 4                                

TestPassed: .asciiz "Test Passed!"
TestFailed: .asciiz "Test Failed!"

.text
# Tests if the given implementation of accumulate is correct.
# Input: a0 contains a pointer to the version of accumulate in question. See lotsofaccumulators.s for more details.
# The main function currently runs a simple test that checks if accumulator works on the given input array.
# Modify the test so that you can catch the bugs in four of the five solutions!

main:
    # Test accumulatorone
    la a0, inputarray
    jal accumulatorone
    li t0, 28
    bne a0, t0, Fail

    # Test accumulatortwo
    la a0, inputarray2
    jal accumulatortwo
    li t0, 16
    bne a0, t0, Fail

    # Test accumulatorthree
    la a0, inputarray3
    jal accumulatorthree
    li t0, 0
    bne a0, t0, Fail

    # Test accumulatorfour
    la a0, inputarray
    jal accumulatorfour
    li t0, 28
    bne a0, t0, Fail

    #Test accumulatorfive
    la a0, inputarray1
    jal accumulatorfive
    li t0, 28
    bne a0, t0, Fail

    j Pass

Fail:
    la a0, TestFailed
    jal print_string
    j End

Pass:
    la a0, TestPassed
    jal print_string
    j End

End:
    jal exit

print_int:
    mv a1, a0
    li a0, 1
    ecall
    jr ra
    
print_string:
    mv a1, a0
    li a0, 4
    ecall
    jr ra
    
exit:
    li a0, 10
    ecall
