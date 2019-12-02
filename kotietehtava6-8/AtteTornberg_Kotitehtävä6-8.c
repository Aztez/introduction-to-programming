#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void tarkistaPin(char tilinumero[], int n);
void valikko(void);
int nostaRahaa(double saldo);
void tiedostonMuokkaus(double saldo, char tilinnumero[], int n);
int lueKokonaisluku(void);
double lueReaaliluku(void);
void lueRoskat(void);

int main(void){

   char tilinumero[30];          // Tämä c-ohjelma on pankkiautomaatti, joka osaa lukea .tili päätteisistä tiedostoista  //
   char tsaldo[30];              // käyttäjän PIN-koodin sekä tilin saldon. Tiedoston nimi toimii tilinumerona.          //
   int n=30;                     // Pankkiautomaatti osaa muokata tiedostossa olevaa saldoa suoritettujen toimintojen    //
   double saldo;                 // mukaan (nosto & talletus).                                                           //
   int summa;
   int valinta;
   double talletus;
   int LOPPU = 0;
   int x;

   FILE *tili;

/*Automaatti kysyy tilinumeroa ja muuttaa sen .tili muotoon avatakseen tiedoston.
  Jos tili on olemassa, kysyy funktio pin-koodia.*/

   printf("\n ----Tervetuloa!----\n");

   while(1){
      printf("\n Syota tilinumerosi: ");
      fgets(tilinumero, 30, stdin);

      if(tilinumero[strlen(tilinumero) -1] == '\n')
         tilinumero[strlen(tilinumero) -1] = '\0';
      else
         lueRoskat();

      strcat(tilinumero, ".tili");

      if((tili = fopen(tilinumero, "r" ))==NULL){
         printf(" Vastaavaa tilia ei ole olemassa\n");
         fclose(tili);
      }

      else {
         fclose(tili);
         if(strstr(tilinumero, x) == NULL) {
            tarkistaPin(tilinumero, n);
         }

      }

   if((tili = fopen(tilinumero, "r" ))==NULL) {
      fclose(tili);
   }
   else if(strstr(tilinumero, x) == NULL) {
      fclose(tili);
      break;
   }

}

   tili = fopen(tilinumero, "r");   /*Tarkistetaan tilin saldo*/
   fgets(tsaldo, 30, tili);
   fgets(tsaldo, 30, tili);
   sscanf(tsaldo, "%lf", &saldo);
   fclose(tili);


   do{
      valikko();
      valinta = lueKokonaisluku();

      switch(valinta){   /*Tässä on valikon runko. Graafinen ulkoasu löytyy valikko funktiosta.*/
         case 1:
            summa = nostaRahaa(saldo);
            saldo = saldo - summa;
			tiedostonMuokkaus(saldo, tilinumero, n);
            break;

         case 2:
            printf(" Syota talletettava summa: ");
            talletus = lueReaaliluku();
            saldo = saldo + talletus;
			tiedostonMuokkaus(saldo, tilinumero, n);
            break;

         case 3:
            printf(" Tilisi saldo on %.2lf euroa\n", saldo);
            break;

         case 0:
            printf("\n    Kiitos kaynnista   \n ja tervetuloa uudelleen!\n\n");
            LOPPU = 1;
            break;

         default: printf("\n Tuntematon komento, yrita uudelleen.\n");
            break;
      }

   }while (!LOPPU);

   return(0);
}


void tarkistaPin(char tilinumero[], int n){  /*Tässä funktiossa kysytään tilinumero ja sen pin-koodi.*/

   char pin[10];
   char tarkpin[10];

   FILE *tili;

   tili = fopen(tilinumero, "r");
   fgets(tarkpin, 10, tili);

   if(tarkpin[strlen(tarkpin) -1] == '\n')
      tarkpin[strlen(tarkpin) -1] = '\0';

   fclose(tili);

   while(strcmp(pin,tarkpin)!=0){
      printf(" Anna PIN-koodi: ");
      fgets(pin, 10, stdin);

      if(pin[strlen(pin) -1] == '\n')
         pin[strlen(pin) -1] = '\0';
      if(pin[strlen(pin) -1] == '\r')
         pin[strlen(pin) -1] = '\0';

      if(strcmp(pin,tarkpin)==0){
         printf(" PIN oikein!\n");
      }

      else if (strcmp(pin,tarkpin)!=0){
         printf(" Virheellinen PIN, yrita uudelleen\n");
      }
   }

}


void valikko(void){   /*Valikko funktio.*/
   printf("\n\n ------Valikko------\n");
   printf(" 1 Nosta kateista\n");
   printf(" 2 Talleta kateista\n");
   printf(" 3 Nayta tilin saldo\n");
   printf(" 0 Lopeta%\n");
   printf("\n Syota valintasi: ");

}


int nostaRahaa(double saldo){   /*NostaRahaa funktio sisältää yksinkertaisen, mutta toimivan funktion seteleiden jaotteluun ja tilin saldon tarkastamiseen.*/

   int nosto;
   int summa = 0;
   int yhteensa;

   printf("\n Tasta automaatista voit nostaa 20 ja 50 euron seteleita.\n Syota summa, jonka haluaisit nostaa: ");
   scanf("%d", &summa);

   while (summa > saldo){
      printf("\n Tilisi saldo ei riita  nain isoon nostoon! Saldosi on %.2lf euroa.\n Yrita uudelleen: ");
      scanf("%d", &summa);
   }

   while(summa < 20 || summa == 30) {
      printf("\n Valitettavasti kyseista summaa ei voi nostaa.\n Tasta automaatista voi nostaa vain 20 ja 50 euron seteleita.\n");

      printf("\n Syota summa, jonka haluaisit nostaa: ");
      scanf("%d", &summa);
   }
   yhteensa = summa;
   int seteli20 = 0;
   int seteli50 = 0;

   while(summa % 50 != 0){
      summa = summa - 20;
      seteli20++;
   }

   seteli50 = summa / 50;

   printf("\n Tassa jaoteltuna nostettavat setelit:\n\n 20 euron setelit: %d\n 50 euron setelit: %d\n Nostit siis: %de\n\n", seteli20, seteli50, yhteensa);

   getchar();


   return(summa);
}


void tiedostonMuokkaus(double saldo, char tilinumero[], int n){   /*saldoon tehdyt muutokset kopiotuvat tiedostoon tällä funktiolla*/

   char temp_pin[30];

   FILE *tili;

   tili = fopen(tilinumero, "r");
   fgets(temp_pin, 30, tili);
   fclose(tili);

   tili = fopen(tilinumero, "w");
   fprintf(tili, "%s", temp_pin);
   fprintf(tili, "%.2lf\n", saldo);
   fclose(tili);

}


double lueReaaliluku(void){

   double luku;
   char mki;
   int status;

   while((status = scanf("%lf%c", &luku, &mki))==0  || (2 == status && mki != '\n') ){
      lueRoskat();
      printf(" Viallinen syotto, yrita uudelleen: ");
   }

   return luku;
}


int lueKokonaisluku(void){

   int luku;
   char mki;
   int status;

   while((status = scanf("%d%c", &luku, &mki))==0  || (2 == status && mki != '\n') ){
      lueRoskat();
      printf(" Viallinen syotto, yrita uudelleen: ");
   }

   return luku;
}


void lueRoskat(void){
     while(fgetc(stdin)!='\n');
}
