#include <Python.h>
#include <iostream>
#include <vector>

using namespace std;
long sievecreate(long n , vector<bool> &prime){
	// long p_no = n;
	for (long p=2; p*p<=n; p++){ 
		if (prime[p] == true){
			for (long i = p*p; i<=n; i += p){
				prime[i] = false;
			}
		} 
	}
	return 1;
	// long p_no = 0; // testing purposes
	// for (long j= 0; j <=n ; ++j){
	// 	if (prime[j]){
	// 		p_no++;
	// 	}
	// }
	// return p_no-2;
}

static PyObject *sieve(PyObject *self, PyObject *args) {
	int input;
	if (!PyArg_ParseTuple(args, "i", &input)) {
		return NULL;
	}
	std::vector<bool> primes (input+2 , true);
    return PyLong_FromLong(sievecreate((long)input ,primes));
};

static PyMethodDef sieveEuthcpp_methods[] = {
		{"sieve", sieve, METH_VARARGS, "Returns a Sieve Of Eratosthenes"},
		{NULL, NULL, 0, NULL},
};

static struct PyModuleDef sieveEuthcpp_defination = {
		PyModuleDef_HEAD_INIT,
		"sieveEuthcpp",
		"Returns a Sieve Of Eratosthenes",
		-1,
		sieveEuthcpp_methods,
};

PyMODINIT_FUNC PyInit_sieveEuthcpp(void) {
	Py_Initialize();
	PyObject *m = PyModule_Create(&sieveEuthcpp_defination);

	return m;
}