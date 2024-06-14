# module for getDaysOfWeek(char *buffer);

    .global getDaysOfWeek
    
    .data

    .text



# TODO - put strings here 
.LC0:
    .string "Su Mo Tu We Th Fr Sa\n"


getDaysOfWeek:
    
    push %rbp
    mov %rsp, %rbp
    
    mov %rdi, %rax
    mov $.LC0, %rsi
    mov %rax, %rdi
    mov $0, %eax
    call sprintf
    pop %rbp
    ret

