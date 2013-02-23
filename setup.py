try:
    from setuptools import setup
except ImportError:
    from distutils import setup
    print 'Didn\'t work'
from distutils.extension import Extension

import numpy as np
# setuptools DWIM monkey-patch madness
# http://mail.python.org/pipermail/distutils-sig/2007-September/thread.html#8204
import sys
if 'setuptools.extension' in sys.modules:
    m = sys.modules['setuptools.extension']
    m.Extension.__dict__ = m._Extension.__dict__
module1 = Extension('hello', sources=['hellomodule.c', 'uname_mod.c'])
pystrings_module = Extension('pystrings', sources=['pystrings.c'])
csleep_module = Extension('csleep', sources=['csleep.c'])
numpy_module = Extension('numpy_extensions', sources=['numpy_extensions.c'], include_dirs=[np.get_include()])
numpy_extension = Extension("numpy_stuff", ["numpy_stuff.pyx", 'doubler.c'], include_dirs=[np.get_include()])
gsw_extension = Extension("gsw_stuff", ["gsw_stuff.pyx"], include_dirs=[np.get_include()], libraries=['gswteos-10'] )
setup(name = 'PackageName', 
        vesrion='0.1',
        description='tutorial',
        ext_modules=[module1, csleep_module, pystrings_module, numpy_module, numpy_extension, gsw_extension],
        py_modules=['gsw_test'],
        setup_requires=['setuptools_cython'],
        )

