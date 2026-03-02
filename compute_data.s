.section .text
.globl compute_nums

compute_nums:
    mov $0, %eax
    test %rsi, %rsi
    jle done
    
loop_computation:
    mov (%rdi), %ecx
    add %ecx, %eax
    add $4, %rdi
    dec %rsi
    jnz loop_computation

done:
    ret

.section .note.GNU-stack,"",@progbits