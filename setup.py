from distutils.core import setup, Extension

extension_mod = Extension("minhash", ["minhashmodule.cpp", "minhash.cpp"])

setup(name = "minhash", ext_modules=[extension_mod])
