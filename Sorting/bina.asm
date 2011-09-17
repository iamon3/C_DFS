

		
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
	;; --initialize mid, start, end ---


	mov dword[ebp-20], 0
	
	mov ebx, dword[ebp-8]
	dec ebx
	mov dword[ebp-24], ebx

	
	;; ------------setMid
	
setMid :
		
	mov eax,dword[ebp-20]
	add eax,ebx
	
	mov ecx,2
	mov edx, 0
	;; 	add ebx,eax
	div ecx
	mov dword[ebp-12],eax

	;; 	mov ecx,dword[ebp-20]
	;; 	call continue

	;; ---printf for elm to b serch
	push str3
	call printf
	add esp,4

	;; ---scanf for elmToBeSearched
	
	mov ecx, ebp
	sub ecx, 16
		
	push ecx
	push str1
	call scanf
	add esp,8

	;; ----initialize [ebp-16]
	;; 	mov dword[ebp-16],ecx
	

	mov ecx,dword[ebp-20]

	;;------------------------------ while loop--------------
	
while :

	cmp ecx,dword[ebp-24]
	jle toExit1
	jmp toExit
	
toExit1:
	mov eax,dword[ebp-24]		 
	mov ebx,dword[ebp-20]
	add eax,ebx
	
	mov ecx,2
	mov edx, 0	
	div ecx
	mov dword[ebp-12],eax
	
	mov ecx,dword[ebp-20]
	
	;; to get arr[mid]

	
	mov eax, dword[ebp-12]
	mov ebx,4
	mul ebx
	
	mov edx, ebp
	sub edx, 64
	add edx,eax
	
	mov edx,dword[edx]
	
	;; error
	cmp edx,dword[ebp-16]
	jl setStart
	
	;; error
	cmp edx,dword[ebp-16]
	jg setEnd

	mov edx,dword[ebp-12]
	inc edx
	push edx
	push str4
	call printf
	add esp,8
	mov esp,ebp
	pop ebp
	ret



;;----------------------------------setStart
	
setStart :
 
	inc dword[ebp-12]
	mov ecx,dword[ebp-12]
	mov dword[ebp-20], ecx	

	jmp while

;;---------------------------------setEnd

setEnd :	
	dec dword[ebp-12]
	mov ecx,dword[ebp-12]
	mov dword[ebp-24],ecx
	mov ecx,dword[ebp-20]

	jmp while

;;;--------------------------------------toExit

toExit:
	push str5
	call printf
	add esp,4
	mov esp, ebp
	pop ebp
	ret
	
;; --------------------------------



	
