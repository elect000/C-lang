  .data
  .align 4
x: .long 0x756f5900, 0x756f6620, 0x6d20646e, 0x000a2165 
y: .long 0x12345678, 0x9abcdef0, 0xfedcba98, 0x19490531 
	.text
  .global main
main:
  mov $0, %edx
  mov $0, %ecx
  mov $0, %ebx
  mov $0, %eax
  mov $0, %esi

  add x(,%esi,4), %edx
  add y(,%esi,4), %edx
  jc  L0
  jmp L00

L00:
  add $1, %esi
  add x(,%esi,4), %ecx
  add y(,%esi,4), %ecx
  jc  L1
  jmp L10

L10:
  add $1, %esi
  add x(,%esi,4), %ebx
  add y(,%esi,4), %ebx
  jc  L2
  jmp L20

L20:
  add $1, %esi
  add x(,%esi,4), %eax
  add y(,%esi,4), %eax
  call stop

L0:
	add $1, %ecx
  jmp L00

L1:
	add $1, %ebx
  jmp L10

L2:
	add $1, %eax
  jmp L20
