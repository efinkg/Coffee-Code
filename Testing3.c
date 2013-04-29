#include <python2.6/Python.h>
#include <stdio.h>

int main(void)
{
      printf ("I am Sending The Stuff");
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
      else{
           printf("Error importing module.");
           exit(-1);
      }
      printf ("The Stuff is Sent");
      return 0;
 }
