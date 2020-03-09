import SieveEuth , time , timeit

def testfunc():
	N = str(int(1e7+2))
	SieveEuth.sieve(N)

def main():
	print(timeit.timeit("testfunc()",  "from __main__ import testfunc" , number = 10)) # 2.9327098510000003

if __name__ == '__main__':
	main()

# orignal = # 2.9327098510000003 (10 reps)
# modified = 2.9157701719999998 (10 reps)