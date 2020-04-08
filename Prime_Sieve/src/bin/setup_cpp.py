from distutils.core import setup, Extension

example_module = Extension(
    'sieveEuthcpp',
    sources=['sieveEuthcpp.cpp'],
    language='C++', )

setup(
    name='sieveEuthcpp',
    version='0.1.0',
    description='sieveEuthcpp module written in C++',
    ext_modules=[Extension('sieveEuthcpp', ['sieveEuthcpp.cpp'])], )
