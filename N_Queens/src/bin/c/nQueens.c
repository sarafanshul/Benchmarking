#include <Python.h>
#include <math.h> 
#include <stdio.h>
#include <string.h>

#define MAXN 31

int nQueensMethod(int n) {
  int q0,q1;
  int cols[MAXN], diagl[MAXN], diagr[MAXN], posibs[MAXN]; // Our backtracking 'stack' 
  int num=0;
  for (q0=0; q0<n-2; q0++) {
	for (q1=q0+2; q1<n; q1++){
	  int bit0 = 1<<q0;
	  int bit1 = 1<<q1;
	  int d=0; // d is our depth in the backtrack stack 
	  cols[0] = bit0 | bit1 | (-1<<n); // The -1 here is used to fill all 'coloumn' bits after n ...
	  diagl[0]= (bit0<<1 | bit1)<<1;
	  diagr[0]= (bit0>>1 | bit1)>>1;
 
	  int posib = ~(cols[0] | diagl[0] | diagr[0]);
 
	  while (d >= 0) {
		while(posib) {
		  int bit = posib & -posib; // The standard trick for getting the rightmost bit in the mask
		  int ncols= cols[d] | bit;
		  int ndiagl = (diagl[d] | bit) << 1;
		  int ndiagr = (diagr[d] | bit) >> 1;
		  int nposib = ~(ncols | ndiagl | ndiagr);
		  posib^=bit; // Eliminate the tried possibility.
		  num += ncols==-1; 
 
		  if (nposib) {
			if (posib) posibs[d++] = posib;
			cols[d] = ncols;
			diagl[d] = ndiagl;
			diagr[d] = ndiagr;
			posib = nposib;
		  }
		}
		posib = posibs[--d]; 
	  }
	}
  }
  return num*2;
}


static PyObject *queens(PyObject *self, PyObject *args) {
	int input;
	if (!PyArg_ParseTuple(args, "i", &input)) {
		return NULL;
	}
    return Py_BuildValue("i" , nQueensMethod((int)input));
};

static PyMethodDef nQueens_methods[] = {
		{"queens", queens, METH_VARARGS, "Returns Number of viable combinations for given N"},
		{NULL, NULL, 0, NULL},
};

static struct PyModuleDef nQueens_defination = {
		PyModuleDef_HEAD_INIT,
		"nQueens",
		"This Module implements N-Queens Puzzle and returns number of viable combinations",
		-1,
		nQueens_methods,
};

PyMODINIT_FUNC PyInit_nQueens(void) {
	Py_Initialize();
	PyObject *m = PyModule_Create(&nQueens_defination);
	return m;
}
 
// int main() {
//     int n = 14;
// 	printf("%d\n%d\n",n ,nQueens(n));
// 	return 0;
// }
//  