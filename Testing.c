#include <python2.6/Python.h>
#include <stdio.h>

void exec_pycode(const char* py_code);

int main(int argc, char* argv[])
{
	Py_Initialize();
	PyRun_SimpleString ("import sys; sys.path.insert(0, '/home/pi/');
        exec_pycode(ccoffeedone);
        return 0;
}


void exec_pycode(const char* py_code)
{
        Py_Initialize();
        PyRun_SimpleString(py_code);
        Py_Finalize();
}
