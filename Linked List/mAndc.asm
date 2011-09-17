
;;--------------------------------------------------data section--------------------------------

;;----------------------------------------text section -----------------------------------------
section .text
	
	extern printf
	extern scanf
	extern atoi
	global main
;;-----------------------------------------main -----------------------------------------------
main:	
	push ebp
	mov ebp,esp

	mov eax, ebp
	sub eax,8

	mov ebx,dword[ebp+8]
	mov ecx,dword[ebp+12]
	
	push dword[ecx+0]
	call atoi
	add esp, 4
	