import numpy as np
cimport numpy as np

np.import_array()

cdef extern from "doubler.h":
    int doubler(size_t len, double *arr)

np.import_array()

cdef int bounce_arr(size_t len, double *a):
    for i in xrange(len):
        a[i]*=2
    return 0

def np_bounce(np.ndarray A not None):
    cdef np.ndarray[np.double_t,ndim=1,mode='c'] retval = np.ascontiguousarray(A,dtype=np.double)
    doubler(retval.shape[0], &retval[0])
    return retval

