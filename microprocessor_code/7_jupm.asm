.model small
.stack 100h
.data
a db "Hello jump $"
b db "Inside jupm code $"
.code
main proc
    mov ax,@data
    mov ds,ax
    
    mov ah,9
    lea dx,a
    int 21h
    
    m:
    mov ah,9
    lea dx,b
    int 21h
    jmp m
    
    exit:
    mov al,4ch
    int 21h
    main endp
end main
    