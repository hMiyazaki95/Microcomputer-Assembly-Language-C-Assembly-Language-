# module for isLeapYear(int year)

    .global isLeapYear
    
    .data

    .text
# TODO - put strings here
isLeapYear:
    push   %rbp
    mov    %rsp, %rbp
        
    push %r12
    push %r13
    
    mov $0, %r12
    mov %rdi, %r13
        
    mov %r13d, %eax
    cdq
    mov $100, %rcx
    idiv %rcx
    mov %eax, %r13d #(year / 100)
    
    mov %r13d, %eax
    cdq
    mov $4, %rcx
    idiv %rcx
    mov %edx, %r13d #(year / 100) % 4
    
    cmp $0, %r13
    jne done
    mov %rdi, %r13
    
    mov %r13d, %eax
    cdq
    mov $100, %rcx
    idiv %rcx
    mov %edx, %r13d #year % 100
    
    mov %r13d, %eax
    cdq
    mov $4, %rcx
    idiv %rcx
    mov %eax, %r13d #year % 100 / 4
    cmp $0, %r13
    jne done
    mov $1, %r12
    
    
done:
    mov %r12, %rax
    pop %r13
    pop %r12
    pop %rbp
    ret

