sub  t1, x28, x29 #t1 = i - j
slli t1, t1, 2    #t1 = t1 * 4
add  t1, t1, x10  #t1 = t1 + A (A[(i - j) * 4])
lw   t1, 0(t1)    #Load (A[(i - j) * 4])[0]
sw   t1, 32(x11)  #Store A[i-j] in B[8 * 4]