#include <stdio.h>
#include <stdlib.h>

int main(void)
{

   double tontinl = 0.0;
   double tontinp = 0.0;
   double talonl = 0.0;
   double talonp = 0.0;
   double leikattava = 0.0;
   double leikkuri = 0.0;
   double aika = 0.0;

   printf("Anna tontin leveys: ");
   scanf("%lf", &tontinl);

   printf("Anna tontin pituus: ");
   scanf("%lf", &tontinp);

   printf("Anna talon leveys: ");
   scanf("%lf", &talonl);

   printf("Anna tontin pituus: ");
   scanf("%lf", &talonp);

   leikattava = (tontinl * tontinp) - (talonl * talonp);
   leikkuri = 0.7 * (5/3.6/60);

   aika = leikattava / leikkuri / 60;

   printf("Nurmikon leikkauksessa kestaa %.2lf minuuttia.", aika);


   return 0;
}
