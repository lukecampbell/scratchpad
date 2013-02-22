import numpy as np
cimport numpy as np

np.import_array()

cdef extern from "gswteos-10.h":
    double gsw_rho(double sa, double ct, double p)

def rho(np.ndarray sa, np.ndarray ct, np.ndarray p):
    if not 1 == sa.ndim == ct.ndim == p.ndim:
        raise TypeError('Not 1-d')
    if not sa.shape[0] == ct.shape[0] == p.shape[0]:
        raise TypeError('Array shapes are not the same')
    cdef np.ndarray[np.double_t, ndim=1] retval = np.empty((sa.shape[0],))
    for i in xrange(sa.shape[0]):
        retval[i] = gsw_rho(sa[i], ct[i], p[i])
    return retval

