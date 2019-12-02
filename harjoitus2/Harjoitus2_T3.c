
/* Algoritmi, joka esittää käyttäjän syöttämän
   pistemäärän arvosanana. */

#include <stdio.h>
#include <stdlib.h>

int main()
{
   int pistemaara;

   printf("Syota kokeesta saamasi pistemaara: ");
   scanf("%d", &pistemaara);


   if(pistemaara >=0 && pistemaara <=11) {
      printf("Arvosana: hylatty\n");

      }else if(pistemaara >= 12 && pistemaara <=13) {
          printf("Arvosana: 1\n");

      }else if(pistemaara >= 14 && pistemaara <=16) {
          printf("Arvosana: 2\n");

      }else if(pistemaara >= 17 && pistemaara <=19) {
          printf("Arvosana: 3\n");

      }else if(pistemaara >= 20 && pistemaara <=22) {
          printf("Arvosana: 4\n");

      }else if(pistemaara >= 23 && pistemaara <=24) {
          printf("Arvosana: 5\n");

      }else{
          printf("virheellinen pistemaara\n");

      }


   return 0;
}
