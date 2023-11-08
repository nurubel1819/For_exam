.model small
.stack 100h
.data
str db "Hi my name is Rubel $"
.code
main proc
    mov ax,@data
    mov ds,ax
    
    mov ah,9   ;9 print string function
    lea dx,str ;lea print string fromate
    int 21h    
    
    mov ah,1   ;input fun
    int 21h
    mov bl,al
    
    mov ah,2   ;end line
    mov dl,10
    int 21h
    mov dl,13 
    int 21h  
    
    mov ah,2
    mov dl,07
    int 21h 
    
    mov ah,2   ;output
    mov dl,bl
    int 21h
    
    exit:
    mov ah,4ch
    int 21h
    main endp
end main



