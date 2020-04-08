import timeit ,json
from utils import (c_py_impl ,
						rust_py_impl ,
						cpp_py_impl)

data = {"Py-C":[],"Py-Cpp":[],"Py-Rs":[]}
def testfuncC(n):
	return c_py_impl(n)

def testfuncRs(n):
	return rust_py_impl(n)

def testfuncCpp(n):
	return cpp_py_impl(n)

def _test(n ,t , _lang):
	_time = timeit.timeit(f"testfunc{_lang}({n})",f"from __main__ import testfunc{_lang}" , number = t)
	# print(_lang ,_time)
	data["Py-"+_lang].append(_time)

def main():
	n = 13
	for i in ("C","Cpp","Rs"):
		for j in range(30):
			_test(n ,1 ,i)

def save():
	with open(r"E:\PRO\Benchmarking\N_Queens\src\benchmarks_data.json", "r+") as bnch_file:
		data_old = json.load(bnch_file)
		# data[_lang].append(_time)
		data_old.update(data)
		bnch_file.seek(0)
		json.dump(data_old ,bnch_file)
		bnch_file.truncate()

if __name__ == '__main__':
	main()
	save()
	print("DOOOOONNNNEEEE")
	# print(data)