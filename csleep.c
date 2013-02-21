#include <Python.h>
#include <unistd.h>

static PyObject *csleep_usleep(PyObject *self, PyObject *args) {
    unsigned long int useconds=0;
    if ( !PyArg_ParseTuple(args,"k", &useconds))
        return NULL;
    usleep((useconds_t) useconds);
    Py_RETURN_NONE;
}

static PyObject *csleep_sleep(PyObject *self, PyObject *args) {
    unsigned int seconds=0;
    if ( !PyArg_ParseTuple(args, "I", &seconds))
        return NULL;
    Py_BEGIN_ALLOW_THREADS
    sleep(seconds);
    Py_END_ALLOW_THREADS
    Py_RETURN_NONE;
}



static PyMethodDef CSleepMethods[] = {
    {"usleep", csleep_usleep, METH_VARARGS, "The usleep() function suspends execution of the calling thread until either useconds microseconds have elapsed or a signal is delivered to the thread whose action is to invoke a signal-catching function or to terminate the thread or process.  The actual time slept may be longer, due to system latencies and possible limitations in the timer resolution of the hardware."},
    {"sleep", csleep_sleep, METH_VARARGS, "he sleep() function suspends execution of the calling thread until either seconds seconds have elapsed or a signal is delivered to the thread and its action is to invoke a signal-catching function or to ter- minate the thread or process.  System activity may lengthen the sleep by an indeterminate amount."},
    {NULL,NULL,0,NULL}
};

PyMODINIT_FUNC initcsleep(void) {
    (void) Py_InitModule("csleep",CSleepMethods);
}



