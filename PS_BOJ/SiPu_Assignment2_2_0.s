.LC0:
        .string "helloworld"
.LC1:
        .string "else helloworld"
main:
        push    rbp
        mov     rbp, rsp
        sub     rsp, 16
        mov     DWORD PTR [rbp-4], 2
        mov     DWORD PTR [rbp-8], 3
        mov     eax, DWORD PTR [rbp-4]
        cmp     eax, DWORD PTR [rbp-8]
        jge     .L2
        mov     edi, OFFSET FLAT:.LC0
        mov     eax, 0
        call    printf
        jmp     .L3
.L2:
        mov     edi, OFFSET FLAT:.LC1
        mov     eax, 0
        call    printf
.L3:
        mov     eax, 0
        leave
        ret