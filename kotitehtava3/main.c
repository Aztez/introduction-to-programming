#include <stdio.h>
#include <stdlib.h>

void tarkistaPIN(void);
void valikko(void);
int lueKokonaisluku(void);
void lueRoskat(void);
void nostaRahaa(void);
void talletaRahaa(void);
void tilinSaldo(void);


int main(void){

   int valinta;
   int maara = -1;
   int LOPPU = 0;

   tarkistaPIN();

   do{
      valikko();
      valinta = lueKokonaisluku();

      switch(valinta){
         case 1:
            nostaRahaa();
            break;

         case 2:
            talletaRahaa();
            break;

         case 3:
            tilinSaldo();
            break;

         case 0: LOPPU = 1;
            break;

         default: printf("Tuntematon komento, yrita uudelleen.\n");
            break;
      }

   }while (!LOPPU);

   system("PAUSE");
   return 0;
}

int lueKokonaisluku(void){
   int luku;
   char mki;
   int result;

   while ((result=scanf("%d%c", &luku, &mki)==0) || (result > 2 && mki !='\n')){

     lueRoskat();
     printf("Ei kelpaa, yrita uudelleen: ");
   }

   return luku;
}

void tarkistaPIN(void){
   int pin;
   int tilinumero;

   printf("Syota tilinumerosi: ");
   scanf("%d", &pin);

   printf("Syota PIN: ");
   scanf("%d", &tilinumero);

}

void lueRoskat(void){
     while(fgetc(stdin)!='\n');
}

void valikko(void){
   printf("\n1 Nosta kateista\n");
   printf("2 Talleta kateista\n");
   printf("3 Nayta tilin saldo\n");
   printf("0 Lopeta%\n");
   printf("\nSyota valintasi: ");

}

void nostaRahaa(void){

   printf("\nValitettavasti valitsemasi toiminto ei ole viela kaytossa.\n");

}

void talletaRahaa(void){

   printf("\nValitettavasti valitsemasi toiminto ei ole viela kaytossa.\n");

}

void tilinSaldo(void){

   printf("\nValitettavasti valitsemasi toiminto ei ole viela kaytossa.\n");

}
