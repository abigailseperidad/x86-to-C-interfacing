section .data
conv dq 255.0

section .text
bits 64
default rel

global imgCvtGrayDoubleToInt
imgCvtGrayDoubleToInt:
    movsd xmm9, [conv]  ; value for conversion

    ; rcx = rows
    ; rdx = cols
    ; r8  = address of dbl_img_arr (double**)
    ; r9  = address of int_img_arr (int**)

    xor r10, r10             ; row counter (i = 0)
outer_loop:
    cmp r10, rcx             ; while i < rows
    jge end_function

    ; Load address of dbl_img_arr[i] (row pointer)
    mov r11, [r8 + r10 * 8]  ; r11 = dbl_img_arr[i]
    mov r12, [r9 + r10 * 8]  ; r12 = int_img_arr[i]

    xor r13, r13             ; column counter (j = 0)
inner_loop:
    cmp r13, rdx             ; while j < cols
    jge next_row

    ; Load dbl_img_arr[i][j]
    movsd xmm1, [r11 + r13 * 8] ; xmm1 = dbl_img_arr[i][j]

    ; Perform conversion
    mulsd xmm1, xmm9            ; xmm1 *= 255.0
    roundsd xmm1, xmm1, 2       ; round up
    cvtsd2si r14, xmm1          ; convert to int (truncate)

    ; Store result in int_img_arr[i][j]
    mov [r12 + r13 * 4], r14    ; int_img_arr[i][j] = (int)xmm1

    inc r13                     ; j++
    jmp inner_loop
next_row:
    inc r10                     ; i++
    jmp outer_loop

end_function:
    ret