from distutils.core import setup, Extension

sugarPersonality_yespower_module = Extension('sugarPersonality_yespower',
                            sources = ['yespower.c', 'yespower-opt.c', 'sha256.c'],
                            extra_compile_args=['-march=native', '-funroll-loops', '-fomit-frame-pointer'],
                            include_dirs=['.'])

setup (name = 'sugarPersonality_yespower',
       version = '1.0',
       description = 'Bindings for yespower proof of work used by sugarchain',
       ext_modules = [sugarPersonality_yespower_module])
