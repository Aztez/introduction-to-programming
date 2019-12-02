#include <stdio.h>
#include <string.h>
#include <ctype.h>

void lueMerkkijono(char mjono[], int koko);
void muutaSuuraakkosiksi(char mjono[]);
void muutaPienaakkosiksi(char mjono[]);

int main(void)
{
   
   char sana[21];
   printf("Anna merkkijono: ");
   lueMerkkijono(sana, 21);
   printf("Syotit sanan: \"%s\"\n", sana);
   
   muutaSuuraakkosiksi(sana);
   printf("Sana suuraakkosina: \"%s\"\n", sana);
   
   muutaPienaakkosiksi(sana);
   printf("Sana pienaakkosina: \"%s\"\n", sana);
     
  system("PAUSE");	
  return 0;
}


void lueMerkkijono(char mjono[], int koko){
   fgets(mjono, koko, stdin);
   
   if(mjono[strlen(mjono)-1]=='\n')
      mjono[strlen(mjono)-1]='\0';
   
   else
      while(fgetc(stdin)!='\n');
}

void muutaSuuraakkosiksi(char mjono[]) {
   int i;
   
   for(i=0; i<strlen(mjono); i++) {
   mjono[i]=toupper(mjono[i]);
            
   }     
     
}

void muutaPienaakkosiksi(char mjono[]) {
   int i;
   
   for(i=0; i<strlen(mjono); i++) {
   mjono[i]=tolower(mjono[i]);
            
   }     
     
}


