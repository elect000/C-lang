  .text
  .global main
f:
  push %ebp
  mov %esp, %ebp
  sub $4, %esp
  movl $3, -4(%ebp)
  cmp $0, 8(%ebp)
  jne L1
  mov -4(%ebp), %eax
  jmp L2

L1: mov 8(%ebp), %eax
  sub $1, %eax
  push %eax
  call f
  /* add $4, %esp */
  add -4(%ebp), %eax

L2:
  mov %ebp, %esp
  pop %ebp
  ret

main:
  mov $3,  %eax
  push %eax
  call f
  call stop
