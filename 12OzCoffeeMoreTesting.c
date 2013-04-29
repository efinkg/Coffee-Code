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
int Kettle = 6;
int Solenoid = 5;
int Grinder = 7;
int Pump = 8;
int TempSensor = 9;
int t = 0;
int i = 0;
int l = 0;
  printf ("Fresh Cup Of Coffee On the Way\n") ;

  if (wiringPiSetup () == -1)
    return 1 ;

  pinMode (Kettle, OUTPUT) ;         // aka BCM_GPIO pin 17
  pinMode (Solenoid, OUTPUT) ;         // aka BCM_GPIO pin 18
  pinMode (Grinder, OUTPUT) ;         // aka BCM_GPIO pin 27
  pinMode (Pump, OUTPUT) ;         // aka BCM_GPIO pin 22
  pinMode (TempSensor, INPUT) ;

double Thermistor(int RawADC) {
 double Temp;
 Temp = log(((10240000/RawADC) - 10000));
 Temp = 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * Temp * Temp ))* Temp );
 Temp = Temp - 273.15;            // Convert Kelvin to Celcius
 Temp = (Temp * 9.0)/ 5.0 + 32.0; // Convert Celcius to Fahrenheit
 return Temp;
}

  for (;;)
 {
  digitalWrite(Pump, 1);
  printf ("Pump Is On\n") ;
  sleep(19);
  digitalWrite(Kettle, 1);
  printf ("Kettle Is On\n") ;
  sleep(45);
  digitalWrite(Pump, 0);
  printf ("Pump Is Off\n") ;
  while(i<18){
  if (Thermistor(digitalRead(TempSensor))<200.0){
  digitalWrite(Kettle, 1);
  printf ("Kettle Is On\n") ;
  } else{
  digitalWrite(Kettle, 0);
  printf ("Kettle Is Off\n") ;
  }
  sleep(1);
  i++;
  };
  printf ("Your Water is At 205 Degrees Fahrenheit\n");
  digitalWrite(Kettle, 0);
  printf ("Kettle Is Off\n") ;
  digitalWrite(Grinder, 1);
  printf ("Grinder Is On\n") ;
  while(t<18){
  if (Thermistor(digitalRead(TempSensor))<200.0){
  digitalWrite(Kettle, 1);
  printf ("Kettle Is On\n") ;
  } else{
  digitalWrite(Kettle, 0);
  printf ("Kettle Is Off\n") ;
  }
  sleep(1);
  t++;
  };
  digitalWrite(Grinder, 0);
  printf ("Grinder Is Off\n") ;
  while(l<18){
  if (Thermistor(digitalRead(TempSensor))<200.0){
  digitalWrite(Kettle, 1);
  printf ("Kettle Is On\n") ;
  } else{
  digitalWrite(Kettle, 0);
  printf ("Kettle Is Off\n") ;
  }
  sleep(1);
  l++;
  };
  digitalWrite(Kettle, 0);
  printf ("Your Water is At 200 Degrees Fahrenheit, For the Perfect Cup of Coffee\n");
  digitalWrite(Solenoid, 1);
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
