
import timeit
import sieveEuthcpp as SieveEuthCpp
import SieveEuth as SieveEuthRs
import sievecpy as SieveEuthCpy
import sieve as SieveEuthPy

import json

N = int(1e7+2)
PRIMES = [True for i in range(int(1e7+2)+1)]

def testfuncRs():
	SieveEuthRs.sieve(str(N))

def testfuncPy():
	global PRIMES
	SieveEuthPy.SieveOfEratosthenes(N ,PRIMES)

def testfuncCpp():
	SieveEuthCpp.sieve(N)

def testfuncCpy():
	global PRIMES 
	SieveEuthCpy.SieveOfEratosthenes(N , PRIMES)

def save(_lang ,_time):
	with open("benchmarks.json", "r+") as bnch_file:
		data = json.load(bnch_file)
		data[_lang].append(_time)
		bnch_file.seek(0)
		json.dump(data ,bnch_file)
		bnch_file.truncate()

def json_init():
	data = {'Rs':[] ,'Cpp':[] ,'Py':[] ,'Cpy':[]}
	with open("benchmarks.json", "w") as bnch_file:
		json.dump(data ,bnch_file)


def main(_lang): 
	print(f'N = {N} \n lang = {_lang} \n Time(10cycles) = ' ,end = ' ')
	_time = timeit.timeit(f"testfunc{_lang}()",f"from __main__ import testfunc{_lang}" , number = 10)
	print(_time)
	save(_lang , _time)

if __name__ == '__main__':
	# json_init()
	_lang = ["Rs" ,"Py" ,"Cpp" ,"Cpy"]
	for i in range(0 ,16):
		main(_lang[i%4])
