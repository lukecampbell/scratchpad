#include <Python.h>
#include <inttypes.h>

static PyObject *make_string(PyObject *self, PyObject *args) {
    PyObject *retval;
    if( !PyArg_ParseTuple(args,""))
        return NULL;

    retval = PyString_FromString("Hello World\n");
    if(retval && retval->ob_refcnt != 1) {
        PyErr_SetString(PyExc_TypeError, "Improper reference count");
        Py_XDECREF(retval);
        return NULL;
    }
    return retval;
}

static PyObject *refcount(PyObject *self, PyObject *args) {
    PyObject *arg;
    PyObject *retval;
    if ( !PyArg_ParseTuple(args, "O", &arg))
        return NULL;
    retval = PyInt_FromLong(arg->ob_refcnt);
    return retval;
}

static PyObject *stuff(PyObject *self, PyObject *args, PyObject *kwargs) {
    uint32_t i=0x0;
    uint32_t j=0x8;
    PyObject *retval;

    static char* keywords[] = {"i", "j",NULL};

    if(!PyArg_ParseTupleAndKeywords(args, kwargs, "I|I", keywords, &i, &j))
        return NULL;

    retval = PyInt_FromLong( i*j );
    return retval;
}




static PyMethodDef PyStringMethods[] = {
    {"make_string", make_string, METH_VARARGS, "Makes a string"},
    {"refcount", refcount, METH_VARARGS, "gets reference counts"},
    {"stuff", (PyCFunction)stuff, METH_VARARGS | METH_KEYWORDS, "Does stuff"},
    {NULL,NULL,0,NULL}
};

PyMODINIT_FUNC initpystrings(void) {
    (void) Py_InitModule("pystrings", PyStringMethods);
}


