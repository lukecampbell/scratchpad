#include <unistd.h>
#include <Python.h>
#include "uname_mod.h"

const char *bad_os = "Darwin";

static PyObject *say_hello(PyObject *self, PyObject *args) {
    const char *name;
    if (!PyArg_ParseTuple(args, "s", &name))
        return NULL;
    printf("Hello %s\n", name);
    Py_RETURN_NONE;
}

static PyObject *get_hello(PyObject *self, PyObject *args) {
    char buf[32];
    if (!PyArg_ParseTuple(args, ""))
        return NULL;
    sysname(buf,32);
    return Py_BuildValue("s", buf);
}

static PyObject *blocker(PyObject *self, PyObject *args) {
    if(!PyArg_ParseTuple(args, ""))
        return NULL;
    Py_BEGIN_ALLOW_THREADS
    sleep(2);
    Py_END_ALLOW_THREADS
    Py_RETURN_NONE;
}


static PyMethodDef HelloMethods[] = {
    {"say_hello", say_hello, METH_VARARGS, "Greet somebody."},
    {"get_hello", get_hello, METH_VARARGS, "Get a string."},
    {"blocker",   blocker,   METH_VARARGS, "C Blocking Call."},
    {NULL, NULL, 0, NULL}
};

PyMODINIT_FUNC inithello(void) {
    (void) Py_InitModule("hello", HelloMethods);
}



