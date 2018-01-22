  .text
  .global determinant
determinant:
  push %ebp
  mov %esp, %ebp

  mov 8(%ebp), %eax
  mov 12(%ebp), %ecx
  imul 16(%ebp), %ecx
  imul 20(%ebp), %eax

  sub %ecx, %eax

  leave
  ret
