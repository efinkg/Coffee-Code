/*
 * Make12Oz.c
 *      Makes a 12oz coffee
 *      Ethan Glassman
 */

#include <stdio.h>
#include <wiringPi.h>

int main (void)
{
int Kettle = 0;
int Solenoid = 1;
int Grinder = 2;
int Pump = 3;
  printf ("Raspberry Pi blink\n") ;

  if (wiringPiSetup () == -1)
    return 1 ;

  pinMode (Kettle, OUTPUT) ;         // aka BCM_GPIO pin 17
  pinMode (Solenoid, OUTPUT) ;         // aka BCM_GPIO pin 18
  pinMode (Grinder, OUTPUT) ;         // aka BCM_GPIO pin 27
  pinMode (Pump, OUTPUT) ;         // aka BCM_GPIO pin 22


  for (;;)
 {
  digitalWrite(Pump, 1);
  printf ("Pump Is On\n") ;
  delay(19000);
  digitalWrite(Kettle, 1);
  printf ("Kettle Is On\n") ;
  delay(45000);
  digitalWrite(Pump, 0);
  printf ("Pump Is Off\n") ;
  delay(280000);
  digitalWrite(Kettle, 0);
  printf ("Kettle Is Off\n") ;
  digitalWrite(Grinder, 1);
  printf ("Grinder Is On\n") ;
  delay(18000);
  digitalWrite(Grinder, 0);
  printf ("Grinder Is Off\n") ;
  digitalWrite(Solenoid, 1);
  printf ("Solednoid Is On\n") ;
  delay(28000);
  digitalWrite(Solenoid, 0);
  printf ("Solenoid Is Off\n") ;
  delay(240000);
  printf ("Your Coffee Is Done\n") ;
 return 0 ;
  }
}
