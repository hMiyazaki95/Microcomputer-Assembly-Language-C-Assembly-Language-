    .global fact
    
    .data
    
    .text
fact:
    push   %rbp
    mov    %rsp, %rbp
    sub    $16, %rsp   
    mov    %rdi, -8(%rbp)

    cmp    $1, -8(%rbp)
    jg     If_Else
    mov    $1, %rax
    jmp    done
    
If_Else:
    mov    -8(%rbp), %rax
    sub    $1, %rax
    mov    %rax, %rdi
    call   fact
    imul   -8(%rbp), %rax

done:
    mov    %rbp, %rsp
    pop %rbp
    ret

