cpdef list SieveOfEratosthenes(int n ,list PRIMES):  # 0.49483466148376465
	# cdef  = [True]*(n+1)
	cdef int p = 2
	cdef int i
	while (p * p <= n): 
		if PRIMES[p]:
			for i in range(p * p, n+1, p): 
				PRIMES[i] = False
		p += 1
	return PRIMES
