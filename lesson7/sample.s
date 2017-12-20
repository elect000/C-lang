	        .text
	        .globl main
	main:   mov $1,%eax
	        mov $2,%ebx
	        mov %eax,%ecx
	        add %ebx,%ecx
	        call stop
