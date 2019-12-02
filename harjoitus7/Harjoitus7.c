#include <stdio.h>
#include <stdlib.h>

typedef struct{
   char sukunimi[31];
   char etunimi[31];
   int opNro;
   int vuosi;
   
}Opiskelija_t;  //tietotyyppi   

void tulostaOpiskelija(Opiskelija_t op);
Opiskelija_t lueOpiskelija(void);
void lueMjono(char mjono[], int pituus);
int lueKokonaisluku(void);
void valikko(void);
int lisaaOpiskelija(Opiskelija_t taulukko[], int maara);
void etsiOpiskelija(Opiskelija_t taulukko[], int maara);
void lueRoskat(void);
void selaa(Opiskelija_t taulukko[], int maara);

int main(void){
    
   Opiskelija_t taulukko[3];
   int i; 
   int maara = -1;
   int valinta;
   int LOPPU = 0;
   
   do{
      valikko();
      valinta = lueKokonaisluku();
      
      switch(valinta){
         case 1:
            if(maara<2){
               maara = lisaaOpiskelija(taulukko, maara);
            }else{
               printf("Rekisteri on taysi\n");
            }
            break;
         
         case 2: 
            if (maara>=0){
               etsiOpiskelija(taulukko, maara);
            }else{
               printf("Rekisteri on tyhja\n");
            }
            break;
         
         case 3: 
            if(maara>=0){
               selaa(taulukko, maara);             
            }else{
               printf("rekisteri on tyhja\n");      
            }
            break;
         
         case 0: LOPPU = 1;
            break;
            
         default: printf("Tuntematon komento, en osaa\n");
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

void valikko(void){
   printf("\n1 Lisaa opiskelija\n");
   printf("2 Etsi opiskelija\n");
   printf("3 Selaa tietoja\n");
   printf("0 Lopeta%\n");
   printf("\nValintasi: ");     
     
}

int lisaaOpiskelija(Opiskelija_t taulukko[], int maara){
   maara++;
   taulukko[maara] = lueOpiskelija();
   
   return maara;
}

Opiskelija_t lueOpiskelija(void){
   Opiskelija_t temp;

   printf("Anna opiskelijan sukunimi: ");
   lueMjono(temp.sukunimi, 31);
   printf("Anna opiskelijan etunimi: ");
   lueMjono(temp.etunimi, 31);
   printf("Anna opiskelijan opiskelijanumero: ");
   temp.opNro=lueKokonaisluku();
   printf("Anna opiskelijan kirjoilletulovuosi: ");
   temp.vuosi=lueKokonaisluku();
      
   return temp;
}

void lueMjono(char mjono[], int pituus){
   fgets(mjono, pituus, stdin);
   
   if(mjono[strlen(mjono)-1]=='\n')
      mjono[strlen(mjono)-1]='\0';
   
   else
      lueRoskat();
}

void etsiOpiskelija(Opiskelija_t taulukko[], int maara){
   int i;
   int loytyi = 0;
   char sukunimi[31];
   
   printf("Syota etsittavan sukunimi: ");
   lueMjono(sukunimi, 31);
   
   for(i=0; i<=maara; i++){
      if(strcmp(sukunimi, taulukko[i].sukunimi)==0){
         loytyi=1;
         tulostaOpiskelija(taulukko[i]);
      }
   }
   
   if(!loytyi)
   printf("Ei loydy mitaan talla sukunimella.\n");
}

void selaa(Opiskelija_t taulukko[], int maara){
   int i=1;
   
   
   for(i=0; i<=maara; i++){
      tulostaOpiskelija(taulukko[i]);
      fgetc(stdin);         
   }
   
}

void tulostaOpiskelija(Opiskelija_t op){
   
   printf("Sukunimi:%s\n", op.sukunimi);
   printf("Etunimi:%s\n", op.etunimi);
   printf("Opiskelijanumero:%d\n", op.opNro);
   printf("Vuosi:%d\n", op.vuosi);
   
}   

void lueRoskat(void){
     while(fgetc(stdin)!='\n');
}
