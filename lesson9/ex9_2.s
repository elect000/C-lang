  .text
  .global sum
sum:
  push %ebp
  mov %esp, %ebp

  mov $0, %eax

  mov 8(%ebp), %edx
  sub $1, %edx
  mov 12(%ebp), %ecx
  jmp L

L:
  add (%ecx,%edx,4), %eax
  sub $1, %edx
	js L2
  jmp L

L2:
  leave
  ret
