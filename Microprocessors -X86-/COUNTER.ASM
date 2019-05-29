assume cs:code
code segment
  start:
    mov cx,100d
    mov bl,00

    next_digit:
        mov ah,00
        mov al,02h
        int 10h
        mov ah,02
        mov dh,12d
        mov dl,40d
        int 10h

        mov al,bl
        aam
        add ax,3030h
        mov dl,ah
        push ax
        mov ah,2
        int 21h
        pop ax

        mov dl,al
        mov ah,2
        int 21h

        mov dl,0dh
        mov ah,2
        int 21h

       call delay
       inc bl
       loop next_digit

       mov ah,4ch
       int 21h
 delay proc
   mov si,0092h
   l1:mov di,00ffh
   l2:dec di
   jnz l2
   dec si
   jnz l1
   ret
 delay endp
code ends
end start
