	  addi x5, x0, 5 # a
	    addi x6, x0, 3 # b  , j < b inner
	    addi x7, x0, 0 # i  , i < a outer
	    #addi sp, sp, -48
	    addi x10, sp, 0
	    li x7, 0
LOOP_OUTER: beq  x7, x5, DONE_OUTER
	    li   x29, 0

LOOP_INNER: beq   x29, x6, DONE_INNER
	    slli  x31, x29, 4    # Assuming D[] is int, so we shift 4, so we get (t2 = j * 4 * 4) 
	    add   x31, x10, x31  # &D + x32
	    add   x30, x7, x29   # i + j
	    sw    x30, 0(x31)

	    addi  x29, x29, 1
	    jal x0 LOOP_INNER
DONE_INNER:
	    addi x7, x7, 1
	    jal x0 LOOP_OUTER
	    
DONE_OUTER: