/*
 * Make12Oz.c
 *      Makes a 12oz coffee
 *      Ethan Glassman
 */

#include <stdio.h>
#include <wiringPi.h>
#include <python2.6/Python.h>
#include <math.h>
#include <time.h>
void exec_pycode(const char* py_code);

int main (void)
{
int Kettle = 1;
int Solenoid = 0;
int Grinder = 2;
int Pump = 3;
int TempSensor = 4;
int t = 0;
int IsItHot = 0;
PyObject *CurrentTemp;
IsItHot = (int) CurrentTemp;

Py_Initialize();
    PyRun_SimpleString ("import sys; sys.path.insert(0, '/Code/Coffee-Code/')");
    PyObject * pModule = NULL;
    PyObject * pFunc   = NULL;
    pModule = PyImport_ImportModule("Thermometer");
    pFunc   = PyObject_GetAttrString(pModule, "HowHot");

    if(pFunc != NULL) {
        CurrentTemp = PyEval_CallObject(pFunc, NULL);
        Py_Finalize();
    }
   else{
       printf ("I Can't Find Things\n");
   }
  Py_DECREF(CurrentTemp);

  printf ("Fresh Cup Of Coffee On the Way\n") ;
  if (wiringPiSetup () == -1)
    return 1 ;

  pinMode (Kettle, OUTPUT) ;         // aka BCM_GPIO pin 17
  pinMode (Solenoid, OUTPUT) ;         // aka BCM_GPIO pin 18
  pinMode (Grinder, OUTPUT) ;         // aka BCM_GPIO pin 27
  pinMode (Pump, OUTPUT) ;         // aka BCM_GPIO pin 22
  pinMode (TempSensor, INPUT) ;

 {
  digitalWrite(Pump, 1);
  printf ("Pump Is On\n") ;
  sleep(19);
  digitalWrite(Kettle, 1);
  printf ("Kettle Is On\n") ;
  sleep(25);
  digitalWrite(Pump, 0);
  printf ("Pump Is Off\n") ;
  while(IsItHot<205){
  digitalWrite(Kettle, 1);
  };
  digitalWrite(Kettle, 0);
  printf ("Kettle Is Off\n") ;
  digitalWrite(Grinder, 1);
  printf ("Grinder Is On\n") ;
  for(t=0; t<18; t++)
  {
  if(IsItHot<200){
  digitalWrite(Kettle,1);
  }
  else{
  digitalWrite(Kettle, 0);
  };
  sleep(1);
  };
  digitalWrite(Grinder, 0);
  printf ("Grinder Is Off\n") ;
  digitalWrite(Solenoid, 1) ;
  printf ("Solednoid Is On\n") ;
  sleep(28);
  digitalWrite(Solenoid, 0);
  printf ("Solenoid Is Off\n") ;
  printf ("Coffee Is Brewing\n") ;
  sleep(60);
  printf ("Your Coffee Has Been Brewing for One Minute\n") ;
  sleep(60);
  printf ("Your Coffee Has Been Brewing for Two Minutes\n") ;
  sleep(60);
  printf ("Your Coffee Has Been Brewing for Three Minutes\n") ;
  sleep(40);
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
  sleep(20);
  printf ("Your Coffee Has Been Brewing for Four Minutes\n") ;
  printf("Your Coffee is Done Brewing, Please Collect\n");
 return 0 ;
  }
}

