from distutils.core import setup, Extension

sugar_yespower_module = Extension('sugar_yespower',
                            sources = ['yespower.c', 'yespower-opt.c', 'sha256.c'],
                            extra_compile_args=['-march=native', '-funroll-loops', '-fomit-frame-pointer'],
                            include_dirs=['.'])

setup (name = 'sugar_yespower',
       version = '1.0',
       description = 'Bindings for yespower proof of work used by cryply',
       ext_modules = [sugar_yespower_module])
