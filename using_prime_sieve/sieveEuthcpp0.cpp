#include <Python.h>

void sievecreate(long n , PyObject* prime ,PyObject* false1 , PyObject* true1){
	Py_ssize_t N = n;
	for (Py_ssize_t p=2; p*p<=N; p++){ 
		// if (prime[p] == true1)
		PyObject *item_idx = PyList_GetItem(prime, p);
		if (item_idx == true1){
		// if (PyList_GetItem(prime, p) == true1){
			for (Py_ssize_t i = p*p; i<=N; i += p){
				// prime[i] = false1;
				Py_INCREF(item_idx);
				PyList_SetItem(prime, i, false1); //
				Py_DECREF(item_idx);
			}
		} 
	} 
}

static PyObject *sieve(PyObject *self, PyObject *args) {
	int input;
	const Py_ssize_t length = input + 2;
	if (!PyArg_ParseTuple(args, "i", &input)) {
		return NULL;
	}
	PyObject *true1 = Py_True;
	Py_INCREF(true1);
	PyObject *false1 = Py_False;
	Py_INCREF(false1);
	PyObject* primes = PyList_New(length);
	PyList_SET_ITEM(primes , length , true1);//

	sievecreate((long)input ,primes , false1 ,true1);

	Py_DECREF(true1);
	Py_DECREF(false1);
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