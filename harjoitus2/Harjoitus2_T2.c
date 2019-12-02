
/* Algoritmi joka esittää käyttäjän celsius-asteissa syöttämän
   lämpötilan Fahrenheiteina ja Kelvineinä. */

#include <stdio.h>
#include <stdlib.h>

int main()
{
   double kelv, fahr, cels;

   printf("Syota lampotila Celsius asteissa: ");
   scanf("%lf", &cels);

   kelv = cels + 273.15;
   fahr = (cels) * 1.8 + 32;

   printf("\nLampotila Kelvineina: %.3lf\nLampotila Fahrenheiteina: %.3lf\n", kelv,fahr);


   return 0;
}
