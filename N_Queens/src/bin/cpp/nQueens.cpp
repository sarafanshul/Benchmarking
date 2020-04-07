#pragma GCC optimize("O3")
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("unroll-loops")

#include <Python.h>
#include <iostream>

using namespace std;

int position[32];
int cnt = 0;

// Check if a position is safe
bool isSafe(int queen_number, int row_position) {
	// Check each queen before this one
	for (int i = 0; i < queen_number; i++) {
		// Get another queen's row_position
		int other_row_pos = position[i];
		// Now check if they're in the same row or diagonals
		if (other_row_pos == row_position || // Same row
			other_row_pos == row_position - (queen_number - i) || // Same diagonal
			other_row_pos == row_position + (queen_number - i))   // Same diagonal
			return false;
	}
	return true;
}

// Recursively generate a tuple like [0 0 0 0], then [0 0 0 1] then etc...
void solve(int k ,int n){
	if (k == n) cnt++;
	else {
		for (int i = 0; i < n; i++) {
			// Before putting a queen (the k-th queen) into a row, test it for safeness
			if (isSafe(k, i)){
				position[k] = i;
				// Place another queen
				solve(k + 1 ,n);
			}
		}
	}
}

static PyObject *queens(PyObject *self, PyObject *args) {
	int input;
	if (!PyArg_ParseTuple(args, "i", &input)) {
		return NULL;
	}
	solve(0, (int)input);
	int ret = cnt;
	cnt = 0;
    return PyLong_FromLong(ret);
};

static PyMethodDef nQueens_methods[] = {
		{"queens", queens, METH_VARARGS, "Returns number of viable combinations for a given N"},
		{NULL, NULL, 0, NULL},
};

static struct PyModuleDef nQueens_defination = {
		PyModuleDef_HEAD_INIT,
		"nQueens",
		"This Module Implements N Queens and returns number of viable combinations for a given N",
		-1,
		nQueens_methods,
};

PyMODINIT_FUNC PyInit_nQueens(void) {
	Py_Initialize();
	PyObject *m = PyModule_Create(&nQueens_defination);

	return m;
}

// int main(){
// 	int n = 10;
  
//   	solve(0 ,n);

// 	cout << cnt <<"\n";
// 	return 0;
// }