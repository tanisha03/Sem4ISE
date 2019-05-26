assume cs:code, ds:data

disp macro msg
        lea dx,msg
        mov ah,09
        int 21h
endm

data segment
   pwd1 db "tanisha"
   len1 db len1-pwd1
   pwd2 db 10 dup(?)
   len2 db ?
   msg1 db 0ah,0dh,"Matched$"
   msg2 db 0ah,0dh,"Not matched $"
   msg3 db 0ah,0dh,"Enter password$"
   msg4 db 0ah,0dh,"Attempts exceeded$"
data ends

code segment
  start:
     mov ax,data
     mov ds,ax
     mov es,ax

     mov bl,0
     rpt: call readpwd
          call match
          inc bl
          cmp bl,03
          jle rpt
          disp msg4
          mov ah,4ch
          int 21h

readpwd proc near
        disp msg3
        mov bh,0
        lea si,pwd2

        again:
            mov ah,8
            int 21h
            cmp al,0dh
            je next
            mov [si],al
            inc si
            inc bh
            mov dl,"*"
            mov ah,2
            int 21h
            jmp again
        next: mov len2,bh
     ret
readpwd endp

match proc near
   mov al,len1
   cmp al,len2
   je now
   jmp mismatch

   now: mov cl,len1
        mov ch,00
        lea si,pwd1
        lea di,pwd2
        cld
        rep cmpsb
        jnz mismatch
        disp msg1
        mov ah,4ch
        int 21h

   mismatch:disp msg2

  ret
match endp

code ends
end start
