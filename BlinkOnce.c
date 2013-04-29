/*
 * Make12Oz.c
 *      Makes a 12oz coffee
 *      Ethan Glassman
 */

#include <stdio.h>
#include <wiringPi.h>

int main (void)
{
  printf ("Raspberry Pi blink\n") ;

  if (wiringPiSetup () == -1)
    return 1 ;

  pinMode (0, OUTPUT) ;         // aka BCM_GPIO pin 17
  pinMode (1, OUTPUT) ;         // aka BCM_GPIO pin 18
  pinMode (2, OUTPUT) ;         // aka BCM_GPIO pin 27
  pinMode (3, OUTPUT) ;         // aka BCM_GPIO pin 22


  for (;;)
  {
    digitalWrite (0, 1) ;       // On
    delay (500) ;               // mS
    digitalWrite (0, 0) ;       // Off
    delay (500) ;
  return 0 ;
   }
}

