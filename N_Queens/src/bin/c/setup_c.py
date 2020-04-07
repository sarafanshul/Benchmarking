from distutils.core import setup, Extension

example_module = Extension(
    'nQueens',
    sources=['nQueens.c'],
    language='C', )

setup(
    name='nQueens',
    version='0.1.0',
    description='This Module implements N-Qunnes Puzzle and returns number of viable combinations',
    ext_modules=[Extension('nQueens', ['nQueens.c'])], 
    )