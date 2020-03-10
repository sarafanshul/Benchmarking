# import SieveEuth , time , timeit # for rs ext
import sievecpy , time , timeit # for cpy ext
PRIMES = [True for i in range(int(1e7+2)+1)]

def testfunc():
	global PRIMES
	N = int(1e7+2)
	sievecpy.SieveOfEratosthenes(N , PRIMES)


def main():
	print(timeit.timeit("testfunc()",  "from __main__ import testfunc" , number = 1)) # 2.9327098510000003
	# testfunc()

if __name__ == '__main__':
	main()

# orignal = # 2.9327098510000003 (10 reps)
# modified = 2.9157701719999998 (10 reps)