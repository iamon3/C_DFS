

		
;; --------------Binary Search-------------------------------------------;;


section .data

	str0 db "Enter Length of Arr :	",10,0
	str1 db "%d",0
	str2 db "Enter elements in sorted order :-",10,0
	str3 db "Enter element you want to search",10,0
	str4 db "Element Found at %d position",10,0
	str5 db "Element not found ",10,0

		
;; ---------------------------------------------------------------------;;

section .text
	extern printf
	extern scanf
	global main

;; ---------------------------------------------------------------------;;

main:
	push ebp
	mov ebp, esp

	;; ----parameters--i,length,mid, elementToBeSearched, end, start, arr[10]
	sub esp, 64
	
;; ---------printf----------------------------------------------------
	
	push str0
	call printf
	add esp ,4

;;---------scanf-----------------------------------------------------

	mov ebx, ebp
	sub ebx, 8
	push ebx
	push str1
	call scanf
	add esp,8

;;----------2nd printf----------------------------------------------

	push str2
	call printf
	add esp,4

;;----------For Loop---------------------------------------------

	;; initialize i to 0
	
	mov dword[ebp-4], 0
	mov ecx, dword[ebp-4]

	;; compare i with lengthOfMatrix
for:	cmp ecx, dword[ebp-8]
	je afterFor

	;; scanf in for loop
	mov ebx, ebp
	sub ebx, 64
	
	mov eax, dword[ebp - 4]
        mov edx, 4 
	mul edx 
	add ebx, eax 
		
	push ebx
	push str1
	call scanf
	add esp, 8

	;;------increment i by 1--------------
	inc dword[ebp-4]
	mov ecx, dword[ebp - 4]
	jmp for

;;------------------------------------------------------------------------ 

afterFor:

	push str3
	call printf
	add esp, 4

	;; --scan elmToBeSorted-------
	
	mov ebx, ebp
	sub ebx, 12
	push ebx
	push str1
	call scanf
	add esp,8

	;; --initialize mid, start, end---

	mov dword[ebp-36], 0 

;;---------------------- 