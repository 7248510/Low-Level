;From gray hat hacking sixth edition
;Lab2-8
section .data
msg db "Hello, world", 0xa ;String with carriage return
len equ $ -msg ;length of String
section .text
    global _start ;loaders

_start:

    mov edx, len
    mov ecx, msg
    mov ebx, 1
    mov eax, 4
    int 0x80 ;sys call #
    mov ebx, 0
    mov eax, 1
    int 0x80
