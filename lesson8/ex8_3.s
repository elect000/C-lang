  .text
	.global main

main:
  mov $20, %edx
	mov $0, %eax
  mov $0, %ebx
  mov $0, %ecx

  cmp $0, %edx
  je  L2

  add $1, %ecx
  mov $1, %eax
  cmp $1, %edx
  je L2
  jmp L1

L1:
  push %eax
  add %ebx, %eax
  pop %ebx
  add $1, %ecx
  cmp %edx, %ecx
  je L2
  jmp L1

L2:
  call stop
