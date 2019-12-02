#include <stdio.h>
#include <stdlib.h>

void nostaRahaa(int summa);

int main(void){

   int summa;

   printf("Tervetuloa!\nTasta automaatista voit nostaa 20 ja 50 euron seteleita.\nSyota summa, jonka haluaisit nostaa: ");
   scanf("%d", &summa);

   while(summa < 20 || summa == 30) {
      printf("\nValitettavasti kyseista summaa ei voi nostaa.\nAutomaatista voi nostaa vain 20 ja 50 euron seteleita.\n");

      printf("\nSyota summa, jonka haluaisit nostaa: ");
      scanf("%d", &summa);
   }


   int seteli20 = 0;
   int seteli50 = 0;

   while(summa % 50 != 0){
      summa = summa - 20;
      seteli20++;
   }

   seteli50 = summa / 50;

   printf("\nTassa jaoteltuna nostettavat setelit:\n\n20 euron setelit: %d\n50 euron setelit: %d\n\nKiitos ja tervetuloa uudelleen!\n\n", seteli20, seteli50);

   getchar();
}
