#include <stdio.h>
#include <string.h>
#include <ctype.h>

void lueMjono(char mjono[], int koko);
void kaannaMjono(char mjono[], char mjono2[]);

int main(void) {
   
   int a;
   char sana[21];
   char sana2[21];
   printf("Anna merkkijono: ");
   lueMjono(sana, 21);
   printf("Syotit sanan: \"%s\"\n", sana);
   
   kaannaMjono(sana, sana2);
   
   a = strcmp(sana, sana2);
   
   if (a == 0){
      
      printf("Merkkijono on palindromi.\n");
  }   
   else {
       printf("Merkkijono ei ole palindromi.\n");
  }    
    
    
    
     
  system("PAUSE");	
  return 0;
}


void lueMjono(char mjono[], int koko){
   fgets(mjono, koko, stdin);
   
   if(mjono[strlen(mjono)-1]=='\n')
      mjono[strlen(mjono)-1]='\0';
   
   else
      while(fgetc(stdin)!='\n');
}


void kaannaMjono(char mjono[], char mjono2[]){
   
   int i;
   int pituus = strlen(mjono);
   
   for(i=0; i<pituus; i++){
      mjono2[i] = mjono[(pituus-1)-i];
     
   }
   mjono2[i]='\0';

}
