# module for getFirstDayOfMonth(int, int)

    .global getFirstDayOfMonth
    
    .data

    .text
getFirstDayOfMonth:
    push %rbp
    mov %rsp, %rbp
    
    #add %rdi, %rsi
    #mov %rsi, %rax
    
    add $9, %rdi # mon + 9
    
    # ax, al, eax, rax
    
    # %edx:eax
    mov %edi, %eax
    cdq    # convert double-word to quad-word
    mov $12, %ecx
    idiv %ecx #devision #idiv is unsigned/ idiv is signed
    mov %edx, %edi # (mon + 9) % 12
    
    inc %rdi    # mon++
    #mov %rdi, %rax
    
    sub $2000, %rsi #rsi # sub -= 2000
    
    cmp $10, %rdi # mon > 10
    jle If_done
    dec %rsi # year--
    
If_done:
    
    push %r14
    push %r15
    
    #first instruction
    
    mov %rdi, %r14 # x = mon
    imul $13, %r14 #x *= 13
    dec %r14
    
    mov %r14d, %eax
    cdq
    mov $5, %r15
    idiv %r15
    mov %eax, %r14d # x = (x/5) /d means equal / eax quatient / edx reminder
    
    mov %rsi, %r15 # tmp = year
    
    mov %r15d, %eax
    cdq
    mov $4, %ecx
    idiv %ecx
    mov %eax, %r15d  # tmp = (tmp / 4)
    
    add %r15, %r14
    add $6, %r14
    add %rsi, %r14
    sub $40, %r14
    
    mov %r14d, %eax
    cdq
    mov $7, %ecx
    idiv %ecx
    mov %edx, %r14d # x= x %7
    
    add $7, %r14
    
    mov %r14d, %eax
    cdq
    mov $7, %ecx
    idiv %ecx
    mov %edx, %r14d # x= x %7
    
    
    mov %r14, %rax
    
    pop %r15
    pop %r14
    
    
    pop %rbp
    ret
