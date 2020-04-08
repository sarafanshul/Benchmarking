from rust.release import nQueens as nQueens_r
from c.build import nQueens as nQueens_c
from cpp.build import nQueens as nQueens_cpp


def c_py_impl(_n) -> int:
	return nQueens_c.queens(_n)

def rust_py_impl(_n) -> int:
	return nQueens_r.queens(str(_n)) #implementation traits in rust force to string

def cpp_py_impl(_n) -> int:
	return nQueens_cpp.queens(_n)

def main():
	print(nQueens_cpp.__doc__)
	print(nQueens_r.__doc__)
	print(nQueens_c.__doc__)

if __name__ == '__main__':
	main()	