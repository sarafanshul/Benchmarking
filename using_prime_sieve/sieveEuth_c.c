#include <Python.h>
#include <math.h> 
#include <stdio.h>
#include <string.h>

long sievecreate(long n , char *prime){
	for (long p=2; p*p<=n; p++){ 
		if (prime[p] == 1){
			for (long i = p*p; i<=n; i += p){
				prime[i] = 0;
			}
		} 
	}
	return n;
}

static PyObject *sieve(PyObject *self, PyObject *args) {
	int input;
	if (!PyArg_ParseTuple(args, "i", &input)) {
		return NULL;
	}
	// std::vector<bool> primes (input+2 , true);
	// bool* primes = new bool[n+1];
	char primes[100002];
	memset(primes, 1, input);
    // return PyLong_FromLong(sievecreate((long)input ,primes));
    return Py_BuildValue("i" ,sievecreate((long)input ,primes));
};

static PyMethodDef sieveEuth_c_methods[] = {
		{"sieve", sieve, METH_VARARGS, "Returns a Sieve Of Eratosthenes"},
		{NULL, NULL, 0, NULL},
};

static struct PyModuleDef sieveEuth_c_defination = {
		PyModuleDef_HEAD_INIT,
		"sieveEuthc",
		"Returns a Sieve Of Eratosthenes",
		-1,
		sieveEuth_c_methods,
};

PyMODINIT_FUNC PyInit_sieveEuth_c(void) {
	Py_Initialize();
	PyObject *m = PyModule_Create(&sieveEuth_c_defination);

	return m;
}