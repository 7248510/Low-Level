;gcc can compile the obj file
; ----------------------------------------------------------------------------
; helloworld.asm
;https://stackoverflow.com/questions/1023593/how-to-write-hello-world-in-assembler-under-windows
; This is a Win32 console program that writes "Hello, World" on one line and
; then exits.  It needs to be linked with a C library.
;There may be errors in the code. Currently I don't know the inner workings of assembly.
; ----------------------------------------------------------------------------
;gcc systemcall.obj -o systest && systest
;nasm -fwin32 systemcall.asm -o systemcall.obj

    global  _main
    extern  _system
    section .text
_main:
    push    message
    call    _system
    add     esp, 4
    ret
message:
    db  'echo some-text  > filename.txt', 0, 0 
    ;db  'echo some-text  > filename.txt', 1, 0
