assume cs:code
code segment
  start:
      mov ah,2ch
      int 21h

      mov al,ch
      aam
      add ax,3030h
      mov bx,ax
      call disp

      mov dl,":"
      mov ah,2
      int 21h

      mov al,cl
      aam
      add ax,3030h
      mov bx,ax
      call disp

      mov ah,4ch
      int 21h


disp proc
  mov dl,bh
  mov ah,2
  int 21h

  mov dl,bl
  mov ah,2
  int 21h
ret
disp endp

code ends
end start
