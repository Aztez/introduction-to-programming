#include <stdio.h>
#include <stdlib.h>

int tarkistaPIN(int pin, int tilinumero);
void valikko(void);
int lueKokonaisluku(void);
void lueRoskat(void);
double nostaRahaa(double saldo);
double talletaRahaa(double saldo);
double tilinSaldo(double saldo);

double saldo;
int pin, tilinumero;

int main(void){

   double tsaldo = 100;
   int valinta;
   int maara = -1;
   int LOPPU = 0;

   tarkistaPIN(pin, tilinumero);

   do{
      valikko();
      valinta = lueKokonaisluku();

      switch(valinta){
         case 1:
            tsaldo = nostaRahaa(tsaldo);
            break;

         case 2:
            tsaldo = talletaRahaa(tsaldo);
            break;

         case 3:
            tsaldo = tilinSaldo(tsaldo);
            break;

         case 0:
            printf("\n    Kiitos kaynnista   \n ja tervetuloa uudelleen!\n\n");
            LOPPU = 1;
            break;

         default: printf("\n Tuntematon komento, yrita uudelleen.\n");
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
     printf(" Ei kelpaa, yrita uudelleen: ");
   }

   return luku;
}

int tarkistaPIN(pin, tilinumero){

   printf(" Syota tilinumerosi: ");
   scanf("%d", &pin);

   printf(" Syota PIN: ");
   scanf("%d", &tilinumero);

}

void lueRoskat(void){
     while(fgetc(stdin)!='\n');
}

void valikko(void){
   printf("\n\n ------Valikko------\n");
   printf(" 1 Nosta kateista\n");
   printf(" 2 Talleta kateista\n");
   printf(" 3 Nayta tilin saldo\n");
   printf(" 0 Lopeta%\n");
   printf("\n Syota valintasi: ");

}

double nostaRahaa(double saldo){
   double nosto;

   printf("\n Syota summa, jonka halua nostaa: ");
   scanf("%lf", &nosto);

   if (nosto > saldo)
      printf(" Tilisi saldo ei riita  nain isoon nostoon! Saldosi on %.2lf euroa.\n Paina mita tahansa nappainta palataksesi valikkoon: ", saldo);

      else{
         saldo = saldo - nosto;

         printf("\n Nostit juuri %.2lf euroa. Tilisi saldo on nyt %.2lf euroa.\n Paina mita tahansa nappainta palataksesi valikkoon: ", nosto, saldo);
      }

   getch();
   return saldo;

}

double talletaRahaa(double saldo){
   double talletus;

   printf("\n Syota summa, jonka haluat tallettaa: ");
   scanf("%lf", &talletus);

   saldo = saldo + talletus;

   printf("\n Talletit juuri %.2lf euroa. Tilisi saldo on nyt %.2lf euroa.\n Paina mita tahansa nappainta palataksesi valikkoon: ", talletus, saldo);
   getch();
   return saldo;

}

double tilinSaldo(double saldo){

   printf("\n Tilisi saldo on %.2lf euroa.\n Paina mita tahansa nappainta palataksesi valikkoon: ", saldo);
   getch();
   return saldo;
}
