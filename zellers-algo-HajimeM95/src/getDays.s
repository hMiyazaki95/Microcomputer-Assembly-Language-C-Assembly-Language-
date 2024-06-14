# module for getDays(buffer*, int, int)

    .global getDays
    
    .data

    .text
MSG:
    .asciz "first day of month: %d\n"

getDays:
    push %rbp
    mov %rsp, %rbp
    
    #callee-saved / caller-owned register / who owns the registers./callee is us
    #putting 4 variables in to
    push %r12   # dayOfWeek
    push %r13   # save param %rdi (buffer)
    push %r14   # save param %rsi (mon)   
    push %r15   # save param %rdx (year)
    
    mov %rdi, %r13  # save buffer ptr
    mov %rsi, %r14  # save mon
    mov %rdx, %r15  # save year
    
    # get dayOfWeek
    mov %r14, %rdi
    mov %r15, %rsi
    call getFirstDayOfMonth
    
    
    # TODO: remove debug sprintf
    
    mov %r13, %rdi # parameter 1 / buffer
    mov $MSG, %rsi # para 2 / massage/format specifier
    mov %rax, %rdx # para 3 /result from getFirstDayOFMonth
    
    xor %rax, %rax
    call sprintf
    xor %rax, %rax 
    
    # TODO: complete calendar
    
    # insert spaces based on getFirstDayOFMonth
    
    # layout spaces row of the calendar
    
    #restoring registers back 
    pop %r15
    pop %r14
    pop %r13
    pop %r12
    
    pop %rbp
    ret
    