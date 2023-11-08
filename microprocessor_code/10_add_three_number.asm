.model small
.stack 100h
.data
ans db ?
.code
main proc
    mov ax,@data
    mov ds,ax
    
    mov ah,1
    int 21h
    mov bh,al
    
    mov ah,1
    int 21h
    mov bl,al
    
    mov ah,1
    int 21h
    mov cl,al
    
    add bh,bl
    sub bh,48
    add bh,cl
    sub bh,48   
    mov ans,bh
    
    mov ah,2
    mov dl,ans
    int 21h  
    
    exit:
    mov ah,4ch
    int 21h
    main endp
end main
    
    


