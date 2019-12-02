
/* Algoritmi työntekijälle maksettavan palakan määrästä*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
   double tuntipalkka,tuntienMaara,veroP,vero,palkka,veroprosentti;

   printf("Syota tuntipalkka: ");
   scanf("%lf", &tuntipalkka);

   printf("Syota tehtyjen tuntien maara: ");
   scanf("%lf", &tuntienMaara);

   do {
      printf("Syota veroprosentti valilta 0-100: ");
      scanf("%lf", &veroprosentti);

   }while(veroprosentti > 100);

   veroP = veroprosentti / 100;
   vero = tuntienMaara * tuntipalkka * veroP;
   palkka = tuntienMaara * tuntipalkka - vero;

   printf("\nVerottajalle meneva osuus: %.2lf euroa.\nTyontekijan palkka: %.2lf euroa.\n", vero, palkka);


   return 0;
}
