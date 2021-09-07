
; You may customize this and other start-up templates; 
; The location of this template is c:\emu8086\inc\0_com_template.txt

MOV CL , 0AH   
MOV SI, 1000H    
MOV [SI], 00H
INC SI
MOV [SI], 01H

XOR AX, AX

MOV BX, 01H
ADD AX, BX
MOV AX, [SI]




