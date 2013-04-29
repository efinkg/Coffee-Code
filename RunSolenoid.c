/*
 * Make12Oz.c
 *      Makes a 12oz coffee
 *      Ethan Glassman
 */

#include <stdio.h>
#include <wiringPi.h>
#include <python2.6/Python.h>
void exec_pycode(const char* py_code);

int main (void)
{
int Kettle = 1;
int Solenoid = 0;
int Grinder = 2;
int Pump = 3;
  printf ("Fresh Cup Of Coffee On the Way\n") ;

  if (wiringPiSetup () == -1)
    return 1 ;

  pinMode (Kettle, OUTPUT) ;         // aka BCM_GPIO pin 17
  pinMode (Solenoid, OUTPUT) ;         // aka BCM_GPIO pin 18
  pinMode (Grinder, OUTPUT) ;         // aka BCM_GPIO pin 27
  pinMode (Pump, OUTPUT) ;         // aka BCM_GPIO pin 22


  for (;;)
 {
  digitalWrite(Solenoid, 1);
  printf ("Solednoid Is On\n") ;
  delay(280000);
  digitalWrite(Solenoid, 0);
  printf ("Solenoid Is Off\n") ;
 return 0 ;
  }
}
