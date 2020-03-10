from distutils.core import setup, Extension

example_module = Extension(
    'sieveEuth_c',
    sources=['sieveEuth_c.c'],
    language='C', )

setup(
    name='sieveEuth_c',
    version='0.1.0',
    description='sieveEuthc module written in C',
    ext_modules=[Extension('sieveEuth_c', ['sieveEuth_c.c'])], )