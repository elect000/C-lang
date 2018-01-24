  .text
  .global main
L0:   //  x == 0 の処理
  mov $0, %eax
  leave
  ret

L1:   //  x == 1 の処理
  mov $1, %eax
  leave
  ret

fib:
  // 旧 ebp 待避
  push %ebp
  // 新 ebp セット
  mov %esp, %ebp

  // x == 1
  cmp $1, %eax
  je L1
  // x == 0
  cmp $0, %eax
  je L0

  // x の待避
  push %eax
  //	fib (x - 1)
  sub $1, %eax
  call fib
  // 計算結果を %ecx に
  mov %eax, %ecx

  // x の復帰
  pop %eax

  //	%ecx = fib (x - 1) を待避
  push %ecx
  //	fib (x - 2)
  sub $2, %eax
  call fib
  // %ecx の復帰
  pop %ecx

  add %ecx, %eax

  leave
  ret

main:
  mov $20, %eax
  call fib
  call stop
