# module for getDays(char *buffer, int mon, int year)

    .global getDays
    
    .data

    .text
# TODO - put strings here

    .string " "
    .string "%3d"
    .string "\n"
    .string " "

getDays:
    push %rbp
    mov %rsp, %rbp
    
    #callee-saved / caller-owned register / who owns the registers./callee is us
    #putting 4 variables in to
    push %r12   # dayOfWeek
    push %r13   # save param %rdi (buffer)
    push %r14   # save param %rsi (mon)   
    push %r15   # save param %rdx (year)
    #push %r16
    #push %r17
    #push %r18
    
    mov %rdi, %r13  # save buffer ptr
    mov %rsi, %r14  # save mon
    mov %rdx, %r15  # save year
    #mov %rcx, %r16 #
    #mov %r8, %r17
    #mov %r9, %r18
    
    # get dayOfWeek
    mov %r14, %rdi
    mov %r15, %rsi   
    call getFirstDayOfMonth
    
    
    # TODO: remove debug sprintf
    
    #mov %r13, %rdi # parameter 1 / buffer
    #mov $MSG, %rsi # para 2 / massage/format specifier
    #mov %rax, %rdx # para 3 /result from getFirstDayOFMonth
    
    #xor %rax, %rax
    #call sprintf
    #xor %rax, %rax 
    
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
