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
int TempSensor = 9;
int t = 0;
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
  }
}
