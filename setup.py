from distutils.core import setup, Extension
import numpy as np

module1 = Extension('hello', sources=['hellomodule.c', 'uname_mod.c'])
pystrings_module = Extension('pystrings', sources=['pystrings.c'])
csleep_module = Extension('csleep', sources=['csleep.c'])
numpy_module = Extension('numpy_extensions', sources=['numpy_extensions.c'], include_dirs=[np.get_include()])
setup(name = 'PackageName', 
        vesrion='0.1',
        description='tutorial',
        ext_modules=[module1, csleep_module, pystrings_module, numpy_module],
        )

