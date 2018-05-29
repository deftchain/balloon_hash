#include <Python.h>

#include "balloon.h"

static PyObject *balloon_getpowhash(PyObject *self, PyObject *args)
{
    char *output;
    PyObject *value;
#if PY_MAJOR_VERSION >= 3
    PyBytesObject *input;
#else
    PyStringObject *input;
#endif
    if (!PyArg_ParseTuple(args, "S", &input))
        return NULL;
    Py_INCREF(input);
    output = PyMem_Malloc(32);

#if PY_MAJOR_VERSION >= 3
    balloon_hash((char *)PyBytes_AsString((PyObject*) input), output, 128, 4);
#else
    balloon_hash((char *)PyString_AsString((PyObject*) input), output, 128, 4);
#endif
    Py_DECREF(input);
#if PY_MAJOR_VERSION >= 3
    value = Py_BuildValue("y#", output, 32);
#else
    value = Py_BuildValue("s#", output, 32);
#endif
    PyMem_Free(output);
    return value;
}

static PyMethodDef balloonMethods[] = {
    { "getPoWHash", balloon_getpowhash, METH_VARARGS, "Returns PoW hash using balloon" },
    { NULL, NULL, 0, NULL }
};

#if PY_MAJOR_VERSION >= 3
static struct PyModuleDef balloonModule = {
    PyModuleDef_HEAD_INIT,
    "balloon_hash",
    "...",
    -1,
    balloonMethods
};

PyMODINIT_FUNC PyInit_balloon_hash(void) {
    return PyModule_Create(&balloonModule);
}

#else

PyMODINIT_FUNC initballoon_hash(void) {
    (void) Py_InitModule("balloon_hash", balloonMethods);
}
#endif
