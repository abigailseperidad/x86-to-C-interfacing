section .data
conv dq 255.0

section .text
bits 64
default rel

global imgCvtGrayDoubleToInt
imgCvtGrayDoubleToInt:
    movsd xmm9, [conv]  ;value for conversion

    ;rcx contains the row value
    ;rdx contains the col value
    ;r8 contains the double array (input)
    ;r9 contains the int array (output)

    ;get first element in r8
    ;multiply with the conversion value (xmm9)
    ;convert to an integer
    ;store it in r9 (integer 2d array)
    ;move to the next element
    ;repeat

    ret