assume cs:code,ds:data
data segment
  fname db "file.txt"
  buff db 100 dup(?)
  msg1 db 0ah,0dh,"File closed$"
  msg2 db 0ah,0dh,"File not found$"
data ends

code segment
  start:
    mov ax,data
    mov ds,ax

    lea dx,fname
    mov al,0
    mov ah,3dh
    int 21h
    jnc next
    lea dx,msg2
    mov ah,9
    int 21h
    jmp finish

    next: mov cx,100d
          lea dx,buff
          mov bx,ax
          mov ah,3fh
          int 21h
          mov cx,100d
          lea si,buff

     readfile: mov dl,[si]
               mov ah,02h
               int 21h
               inc si
               loop readfile
               mov ah,3ch
               int 21h
               lea dx,msg1
               mov ah,9
               int 21h

     finish: mov ah,4ch
             int 21h

 code ends
end start

