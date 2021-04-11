%macro print 2
  mov   eax, 4
  mov   ebx, 1
  mov   ecx, %1
  mov   edx, %2
  int   80h
%endmacro

%macro copy 3
  mov   ecx, %3
  mov   esi, %2
  mov   edi, %1
  cld
  rep   movsb
%endmacro

%macro replace_head 3
  mov   al, [%1]
  cmp   al, %3
  je    fequal
s:
  mov   ecx, %2
  mov   ebx,  0
_loop:
  mov   al, [%1+ebx]
  cmp   al, " "
  je    space
  add   ebx, 1
  loop  _loop
  jmp   exit
space:
  add   ebx, 1
  mov   al, [%1+ebx]
  cmp   al, %3
  je    equal
  loop  _loop
equal:
  mov   [%1+ebx], byte "$"
  loop  _loop
fequal:
  mov   [%1], byte "$"
  jmp   s
exit:
%endmacro

section	.text
   global _start

_start:
  replace_head s1, len1, "c"
  print s1, len1

  mov eax,1
  mov ebx, 0
  int 0x80

section	.data
  s1   db  "complete code - steve mcconell, clean code - robert martin", 0xa, 0xb
  len1 equ $ - s1
