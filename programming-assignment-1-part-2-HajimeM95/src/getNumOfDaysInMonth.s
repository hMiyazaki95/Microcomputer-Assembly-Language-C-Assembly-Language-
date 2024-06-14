# module for getNumOfDaysInMonth(int mon, int year)

    .global getNumOfDaysInMonth
    
    .data

    .text
# TODO - put strings here

getNumOfDaysInMonth:
    push %rbp
    mov %rsp, %rbp
    
    push %r12
    push %r13
    push %r14
    
    mov %rdi, %r13 #Month
    mov %rsi, %r14 #Year
    
    cmp $1, %r13
    jne .2
    mov $31, %r12
    jmp done
    
.2:
    cmp $2, %r13
    jne .3
    mov    %r14, %rax
    mov    %rax, %rdi
    mov    $0, %rax
    call    isLeapYear
    cmp    $1, %rax
    jne .Not_leapyear
    mov $29, %r12
    jmp done
    
.Not_leapyear:
    mov $28, %r12
    jmp done
    
.3:
    cmp $3, %r13
    jne .4
    mov $31, %r12
    jmp done

.4:
    cmp $4, %r13
    jne 5
    mov $30, %r12
    jmp done
    
.5:
    cmp $5, %r13
    jne .6
    mov $31, %r12
    jmp done
    
.6:
    cmp $6, %r13
    jne .7
    mov $30, %r12
    jmp done
    
.7:
    cmp $7, %r13
    jne .8
    mov $31, %r12
    jmp done
    
.8:
    cmp $8, %r13
    jne .9
    mov $31, %r12
    jmp done
    
.9:
    cmp $9, %r13
    jne .10
    mov $30, %r12
    jmp done
    
.10:
    cmp $10, %r13
    jne .11
    mov $31, %r12
    jmp done
    
.11:
    cmp $11, %r13
    jne .12
    mov $30, %r12
    jmp done
    
.12:
    cmp $12, %r13
    jne done
    mov $31, %r12
    
done:
    mov %r12, %rax
    
    pop %r14
    pop %r13
    pop %r12
    
    pop %rbp
    ret

