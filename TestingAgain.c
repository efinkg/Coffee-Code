#include <python2.6/Python.h>

int main()
{

    Py_Initialize();
    PyRun_SimpleString ("import sys; sys.path.insert(0, '/home/pi/')");
    PyObject * pModule = NULL;
    PyObject * pFunc   = NULL;

    pModule = PyImport_ImportModule("CoffeeDone");
    pFunc   = PyObject_GetAttrString(pModule, "SendEmail");
    if(pFunc != NULL) {
        PyEval_CallObject(pFunc, NULL);
        Py_Finalize();
    }
    else {
        printf("pFunc returned NULL\n");
    }

    return 0;
}
