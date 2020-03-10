#include<iostream>
#include <Python.h>
#include <vector>
using namespace std;


// void sievecreate(long n , bool prime[]){
// void sievecreate(long n , vector<bool> &prime){
void sievecreate(long n , PyObject* prime){
	const Py_ssize_t N = n;
	for (Py_ssize_t p=2; p*p<=N; p++){ 
		// if (prime[p] == true) 
		if ((PyList_GetItem(prime, p) )== (Py_True)){
			for (Py_ssize_t i=p*p; i<=N; i += p) 
				// prime[i] = false;
				PyList_SetItem(prime, i, Py_False); 
		} 
	} 
}

static PyObject *sieve(PyObject *self, PyObject *args) {
	int input;
	if (!PyArg_ParseTuple(args, "i", &input)) {
		return NULL;
	}

	// return PyLong_FromLong((long)input * (long)input);
	// vector<bool> primes ((int)input,true);
	// bool* primes = new bool[input+1];
	
	const Py_ssize_t length = input + 2;
	PyObject* primes = PyList_New(length);
	PyList_SET_ITEM(primes , input , Py_True);

	sievecreate((long)input ,primes);
	// return Py_BuildValue("[items]" ,primes);
	// return Py_BuildValue("[ii]" ,primes); // here
	// PyObject * python_lst = Py_BuildValue("[ii]", primes);
    return primes;
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