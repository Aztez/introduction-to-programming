
//Tämä harjoitus on vielä kesken!!!!

#include <stdio.h>
#include <stdlib.h>

typedef struct{
   char sukunimi[31];
   char etunimi[31];
   int opNro;
   int vuosi;
   
}Opiskelija_t;  //tietotyyppi   

void valikko(void);

void lisaaOpiskelija(void);
void etsiOpiskelija(void);
void selaa(void);

Opiskelija_t lueOpiskelija(void);
void tulostaOpiskelija(Opiskelija_t op);

void lueMjono(char mjono[], int pituus);
int lueKokonaisluku(void);
void lueRoskat(void);


int main(void){
    
   Opiskelija_t taulukko[3];
   int valinta;
   int LOPPU = 0;
   
   do{
      valikko();
      valinta = lueKokonaisluku();
      
      switch(valinta){
         case 1:
            lisaaOpiskelija();
            break;
         
         case 2: 
            etsiOpiskelija();
            break;
         
         case 3: 
            selaa();             
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

void lisaaOpiskelija(void){
   FILE * rekisteri;
   Opiskelija_t op;
   
   if((rekisteri = fopen("Opiskelijat.txt", "a"))==NULL)
      printf("Avaaminen ei onnistunut!");
   else {
      op = lueOpiskelija();
      fwrite(&op, sizeof(Opiskelija_t), 1, rekisteri);
      fclose(rekisteri);
      printf("Tiedot tallennettiin");     
   }
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

void etsiOpiskelija(void){
    
    
    
    
}

void selaa(void){
   FILE * rekisteri;
   Opiskelija_t op;
   
   if((rekisteri = fopen("Opiskelijat.txt", "a"))==NULL)
      printf("Avaaminen ei onnistunut!");
   else {
      
   }
   
   
   
   
   
}

void tulostaOpiskelija(Opiskelija_t op){
   
   printf("\nSukunimi:%s\n", op.sukunimi);
   printf("Etunimi:%s\n", op.etunimi);
   printf("Opiskelijanumero:%d\n", op.opNro);
   printf("Vuosi:%d\n", op.vuosi);
   
}   

void lueRoskat(void){
     while(fgetc(stdin)!='\n');
}
