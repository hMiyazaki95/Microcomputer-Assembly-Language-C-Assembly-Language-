    .global main
    
    .data

    .text
    
.Printf:
    .string "%d"
    
main:
    push %rbp
    
    mov $5, %rdi
    call fact
    
    mov %rax, %rsi
    mov $.Printf, %rdi
    mov $0, %rax
    call printf
    mov $0, %rax
    
    pop %rbp
    ret
    