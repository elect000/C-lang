  .text
  .global make_allone_array
make_allone_array:
  push %ebp
  mov %esp, %ebp

  mov 8(%ebp), %ecx
  sub $1, %ecx

	push %edx
  push %ecx

  mov 8(%ebp), %eax
  imul $4, %eax
  push %eax
  call malloc

  pop %ecx
  pop %ecx
  pop %edx
  jmp L
L:
  add $1, (%eax,%ecx,4)
  sub $1, %ecx
  js L2
  jmp L

L2:
  leave
  ret
