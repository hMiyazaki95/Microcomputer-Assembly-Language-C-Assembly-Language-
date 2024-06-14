# module for getMonthYear(char *buffer, int mon, int year)

    .global getMonthYear
    .type getMonthYear, @function
    
    .data

    .text
# TODO - put strings here
.January:
    .string "January %d\n"
    
.February:
    .string "February %d\n"
    
.March:
    .string "March %d\n"
    
.April:
    .string "April %d\n"
    
.May:
    .string "May %d\n"
    
.June:
    .string "June %d\n"
    
.July:
    .string "July %d\n"
    
.August:
    .string "August %d\n"
    
.September:
    .string "September %d\n"
    
.October:
    .string "October %d\n"
    
.November:
    .string "November %d\n"
    
.December:
    .string "December %d\n"
        
getMonthYear:
    push   %rbp
    mov    %rsp, %rbp
    
    push %r12
    push %r13   # save param %rdi (buffer)
    push %r14   # save param %rsi (mon)
    push %r15   # save param %rdx (year)
    
    mov %rdi, %r13  # save buffer ptr
    mov %rsi, %r14  # save mon
    mov %rdx, %r15  # save year
    
    cmp $1, %r14
    jne .2
    mov %r15, %rdx  # buffer
    mov %r13, %rax
    mov $.January, %rsi  # message/format specifier
    mov %rax, %rdi
    
    mov $0, %rax
    call sprintf
    jmp .13
    
.2:
    cmp $2, %r14
    jne .3
    mov %r15, %rdx  # buffer
    mov %r13, %rax
    mov $.February, %rsi  # message/format specifier
    mov %rax, %rdi
    mov $0, %rax
    call sprintf
    jmp .13
    
.3:
    cmp $3, %r14
    jne .4
    mov %r15, %rdx  # buffer
    mov %r13, %rax
    mov $.March, %rsi  # message/format specifier
    mov %rax, %rdi
    mov $0, %rax
    call sprintf
    jmp .13
.4:
    cmp $4, %r14
    jne .5
    mov %r15, %rdx  # buffer
    mov %r13, %rax
    mov $.April, %rsi  # message/format specifier
    mov %rax, %rdi
    mov $0, %rax
    call sprintf
    jmp .13
    
.5:
    cmp $5, %r14
    jne .6
    mov %r15, %rdx  # buffer
    mov %r13, %rax
    mov $.May, %rsi  # message/format specifier
    mov %rax, %rdi
    mov $0, %rax
    call sprintf
    jmp .13

.6:
    cmp $6, %r14
    jne .7
    mov %r15, %rdx  # buffer
    mov %r13, %rax
    mov $.June, %rsi  # message/format specifier
    mov %rax, %rdi
    mov $0, %rax
    call sprintf
    jmp .13
    
.7:
    cmp $7, %r14
    jne .8
    mov %r15, %rdx  # buffer
    mov %r13, %rax
    mov $.July, %rsi  # message/format specifier
    mov %rax, %rdi
    mov $0, %rax
    call sprintf
    jmp .13
    
.8:
    cmp $8, %r14
    jne .9
    mov %r15, %rdx  # buffer
    mov %r13, %rax
    mov $.August, %rsi  # message/format specifier
    mov %rax, %rdi
    mov $0, %rax
    call sprintf
    jmp .13
    
.9:
    cmp $9, %r14
    jne .10
    mov %r15, %rdx  # buffer
    mov %r13, %rax
    mov $.September, %rsi  # message/format specifier
    mov %rax, %rdi
    mov $0, %rax
    call sprintf
    jmp .13
    
.10:
    cmp $10, %r14
    jne .11
    mov %r15, %rdx  # buffer
    mov %r13, %rax
    mov $.October, %rsi  # message/format specifier
    mov %rax, %rdi
    mov $0, %rax
    call sprintf
    jmp .13
    
.11:
    cmp $11, %r14
    jne .12
    mov %r15, %rdx  # buffer
    mov %r13, %rax
    mov $.November, %rsi  # message/format specifier
    mov %rax, %rdi
    mov $0, %rax
    call sprintf
    jmp .13
    
.12:
    cmp $12, %r14
    jne .13
    mov %r15, %rdx  # buffer
    mov %r13, %rax
    mov $.December, %rsi  # message/format specifier
    mov %rax, %rdi
    mov $0, %rax
    call sprintf
    
.13:

    pop %r15
    pop %r14
    pop %r13
    pop %r12
    
    pop %rbp
    ret
