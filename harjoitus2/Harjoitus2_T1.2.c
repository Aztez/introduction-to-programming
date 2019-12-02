
/* Algoritmi joka laskee kuinka kauan mmatka maasta
   Proxima Centauriin kest‰‰ ‰‰nen nopeudella. */

#include <stdio.h>
#include <stdlib.h>

int main()
{
   double etaisyys = 4.2, nopeus = 343, valovuosi = 9.46*10e15, matka, kesto, kestoVuosina;

   matka = etaisyys * valovuosi;
   kesto = matka / nopeus;
   kestoVuosina = kesto * 3.16887646 * 10e-8; //muutetaan sekunnit vuosiksi

   printf("\nMatka Proxima Centauriin kestaa %.lf vuotta.\n", kestoVuosina);

    return 0;
}
