import numpy as np
cimport numpy as np

np.import_array()

cdef extern from "gswteos-10.h":
    double gsw_rho(double sa, double ct, double p)

def rho(double sa, double ct, double p):
    return gsw_rho(sa,ct,p)

