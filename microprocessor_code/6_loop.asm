.model small
.stack 100h
.data
str db "Loop example $"
.code
main proc
    mov ax,@data
    mov ds,ax
    
    mov ah,9
    lea dx,str
    int 21h   
    
    mov ah,2
    mov dl,10
    int 21h
    mov dl,13
    int 21h
    
    mov cx,26
    mov ah,2
    mov dl,'A'
    
    rubel:   
    int 21h
    inc dl
    loop rubel
    
    
    exit:
    mov ah,4ch
    int 21h
    main endp
end main



