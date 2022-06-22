# Disable ASLR at compile time:
    sudo bash -c "echo 0 > /proc/sys/kernel/randomize_va_space"

# Remove protections
    gcc -ggdb -mpreferred-stack-boundary=3 -fno-stack-protector -o OUTPUTFILENAME FILE.C

# GDB: 
* set disassembly-flavor intel
* set disassembly-flavor att
* show disassembly-flavor 
* disas main(dissasembles the main function)
* b (line number)
* list (can view the source code if you have the correct tag) example = list 1,15 (the first line & )
* info proc mappings(information on the running process)
# Remove protections
* gcc -ggdb -mpreferred-stack-boundary=3 -fno-stack-protector -o OUTPUTFILENAME FILE.C

# Lessons learned:
* Make sure your viewing the right register in GDB.
* Use the right shellcode for the correct program
* If you create a vulnerable program use 32 bit shellcode. Compile with -m32
* The Stack is operates first in last out
* EBP/RDP is the calculation of addresses related to each other
* The stack grows via lower numbers. Lower the numbers higher the place. The stack stores instructions in the EAX.

# Instructions:
* EIP/RIP = Instruction pointer
* ESP/RSP = Stack pointer
