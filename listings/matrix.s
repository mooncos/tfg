matmul:
  push {ip, lr}

  @--read rows and columns of matrix A
  ldr r0, <main+0x00ba>
  ldr r1, =linesA
  ldr r2, =columnsA
  mov r3, #1

  @--read all values of matrix A
  ldr r4, =linesA
  ldr r4, [r4]
  ldr r5, =columnsA
  ldr r5, [r5]
  mul r6, r4, r5
  ldr r7, =matrixA

  @--read lines and columns of matrix B
  ldr r0, <main+0x00ca>
  ldr r1, =linesB
  ldr r2, =columnsB
  mov r4, #1

  @--read all values of matrix B
  ldr r4, =linesB
  ldr r4, [r4]
  ldr r5, =columnsB
  ldr r5, [r5]
  mul r6, r4, r5
  ldr r7, =matrixB
    
  @--load all the necessary values on registers r4-r9
  ldr r4, =matrixA
  ldr r5, =linesA
  ldr r5, [r5]
  ldr r6, =columnsA
  ldr r6, [r6]
  ldr r7, =matrixB
  ldr r8, =linesB
  ldr r8, [r8]
  ldr r9, =columnsB
  ldr r9, [r9]

  @--perform calculations and store result
  mov r0, #0
  forLinesA:
    cmp r0, r5
    bge endForLinesA
    mov r1, #0
    forColumnsB:
      cmp r1, r9
      bge endForColumnsB
      mov r2, #0 
      mov r3, #0
      multiply:
        mov r12, #4
        cmp r3, r6
        bge endMultiply
        @--load first element, from matrixA
        mul r10, r0, r6
        add r10, r10, r3
        mul r11, r10, r12
        add r11, r11, r4
        ldr r10, [r11]
        @--load second elements, from matrixB
        mul r11, r9, r3
        add r11, r11, r1
        push {r0}
        mul r0, r11, r12
        add r0, r0, r7
        ldr r11, [r0]
        pop {r0}
        @--multiply and add to result variable
        mul r12, r10, r11
        add r2, r2, r12
        @--loop 
        add r3, r3, #1
        b multiply
      endMultiply:
      b forColumnsB
    endForColumnsB:
    @--loop
    sub r10, r5, #1
    cmp r0, r10
    bge endif2
    push {r0-r12}
    ldr r0, =DMAtransfer1
    bl printf
    pop {r0-r12}
    endif2:
    add r0, r0, #1
    b forLinesA
  endForLinesA:        
   b <main+0x0121>