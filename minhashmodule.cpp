#include "minhash.h"
#include <Python.h>

extern "C" {
  
static PyObject* minhash_wrapper(PyObject* self, PyObject* args) {
  char* s;
  unsigned int k;
  unsigned int seed;
  Min result;
  PyObject* ret = PyList_New(2);

  if (!PyArg_ParseTuple(args, "sII", &s, &k, &seed)) {
    return NULL;
  }

  result = minhash(s, k, seed);

  PyObject* hash_val = PyLong_FromUnsignedLong(result.hash);
  PyObject* kmer_pos = PyLong_FromUnsignedLong(result.pos);
  PyList_SetItem(ret, 0, hash_val);
  PyList_SetItem(ret, 1, kmer_pos);

  return ret;
}

static PyMethodDef ModuleFunctions[] = {
  { "minhash", minhash_wrapper, METH_VARARGS, "MinHash" },
  { NULL, NULL, 0, NULL }
};
  
static struct PyModuleDef ModuleDef = {
  PyModuleDef_HEAD_INIT,
  "minhash",           /* m_name */
  NULL,                /* m_doc */
  -1,                  /* m_size */
  ModuleFunctions,     /* m_methods */
  NULL,                /* m_reload */
  NULL,                /* m_traverse */
  NULL,                /* m_clear */
  NULL,                /* m_free */
};

PyMODINIT_FUNC PyInit_minhash(void) {
  return PyModule_Create(&ModuleDef);
}

}
