  .text
  .global main
main:
  mov $0, %edx
  mov $1, %edi
  /* loop */
Label0:
  add %edi, %edx
  add $1, %edi
  cmp $11, %edi
  jne Label0
  /* loop end */
  call stop
