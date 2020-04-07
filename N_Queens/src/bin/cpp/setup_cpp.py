from distutils.core import setup, Extension

example_module = Extension(
    'nQueens',
    sources=['nQueens.cpp'],
    language='C++', )

setup(
    name='nQueens',
    version='0.1.0',
    description='This Module Implements N Queens and returns number of viable combinations for a given N',
    ext_modules=[Extension('nQueens', ['nQueens.cpp'])], )