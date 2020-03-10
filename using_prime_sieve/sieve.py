'''
Segmented Sieve
			
		The idea of segmented sieve is to divide the range [0..n-1] in 
			different segments and compute primes in all segments one by one. 
			This algorithm first uses Simple Sieve to find primes smaller than or 
			equal to √(n). Below are steps used in Segmented Sieve.

			Use Simple Sieve to find all primes upto square root of ‘n’ and 
			store these primes in an array “prime[]”. Store the found primes 
			in an array ‘prime[]’.
			We need all primes in range [0..n-1]. We divide this range in 
			different segments such that size of every segment is at-most √n
			Do following for every segment [low..high]
			Create an array mark[high-low+1]. Here we need only O(x) space 
			where x is number of elements in given range.
			Iterate through all primes found in step 1. For every prime, 
			mark its multiples in given range [low..high].
			In Simple Sieve, we needed O(n) space which may not be feasible
			 for large n. Here we need O(√n) space and we process smaller 
			 ranges at a time (locality of reference)
'''


from time import time
import math


N = int(1e5 +2)
PRIMES = [ True for i in range(N+1)]

def sieve(N): # 0.9648633003234863
	for i in range(2 ,N):
		if not PRIMES[i] : continue
		for j in range(i+i , N , i):
			PRIMES[j] = False

def SieveOfEratosthenes(n ,PRIMES):  # 0.49483466148376465
	p = 2
	while (p * p <= n): 
		if PRIMES[p]:
			for i in range(p * p, n+1, p): 
				PRIMES[i] = False
		p += 1
		
prime = [] 
  
# This method finds all primes  
# smaller than 'limit' using  
# simple sieve of eratosthenes.  
# It also stores found primes in list prime 
def simpleSieve(limit): 
	  
	# Create a boolean list "mark[0..n-1]" and   
	# initialize all entries of it as True.  
	# A value in mark[p] will finally be False  
	# if 'p' is Not a prime, else True.  
	mark = [True for i in range(limit + 1)] 
	p = 2
	while (p * p <= limit): 
		  
		# If p is not changed, then it is a prime  
		if (mark[p] == True):  
			  
			# Update all multiples of p  
			for i in range(p * p, limit + 1, p):  
				mark[i] = False  
		p += 1
		  
	# Print all prime numbers  
	# and store them in prime  
	for p in range(2, limit):  
		if mark[p]: 
			prime.append(p)
			  
# Prints all prime numbers smaller than 'n'  
def segmentedSieve(n):

	limit = int(math.floor(math.sqrt(n)) + 1) 
	simpleSieve(limit) 

	low = limit 
	high = limit * 2

	while low < n: 
		if high >= n: 
			high = n 

		mark = [True for i in range(limit + 1)] 

		for i in range(len(prime)): 
			loLim = int(math.floor(low / prime[i]) * prime[i]) 
			if loLim < low: loLim += prime[i] 
			for j in range(loLim, high, prime[i]): mark[j - low] = False

		low = low + limit 
		high = high + limit 


def main():
	s = time()
	# sieve(N)
	# SieveOfEratosthenes(N)
	segmentedSieve(N)
	print(time() - s)
	# print(*[i for i in enumerate(PRIMES) if i[-1]][:100] , sep = "\n")

if __name__ == '__main__':
	main()

# ============================ TESTS ==============================

#	NAME 				 	N   		TIME(s)
#	sieve(most Simple) 		~1e5		0.09296941757202148
#	sieve(most Simple) 		~1e6		0.8980965614318848
#	sieve(most Simple) 		~1e7		10.56386661529541

#	Sieve of Euratoshenes 	~1e5		0.04687333106994629
#	Sieve of Euratoshenes 	~1e6		0.45984935760498047
#	Sieve of Euratoshenes 	~1e7		4.970266103744507
		
#	sieve(most Simple) 		~1e5		0.15268778800964355
#	sieve(most Simple) 		~1e6		1.4137709140777588
#	sieve(most Simple) 		~1e7		11.390690565109253

# RESULTS -> SoE is fastest
#		  -> SegS is better locality of reference