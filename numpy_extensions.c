#include <Python.h>
#include <numpy/arrayobject.h>
#include <inttypes.h>

static PyObject *get_float(PyObject *self, PyObject *args) {
    float v = 32;
    PyObject *np_float32_val = NULL;
    PyArray_Descr *descr = NULL;
    if(! PyArg_ParseTuple(args, ""))
        return NULL;
    if(! (descr = PyArray_DescrFromType(NPY_FLOAT32))) {
        PyErr_SetString(PyExc_TypeError, "Improper descriptor");
        return NULL;
    }

    np_float32_val = PyArray_Scalar(&v, descr, NULL);
    printf("%lu\n", np_float32_val->ob_refcnt);
    return np_float32_val;
}

static PyMethodDef NumpyExtensionMethods[] = {
    {"get_float", get_float, METH_VARARGS, "returns a float value"},
    {NULL,NULL,0,NULL}
};

PyMODINIT_FUNC initnumpy_extensions(void) {
    (void) Py_InitModule("numpy_extensions", NumpyExtensionMethods);
    import_array();
}

