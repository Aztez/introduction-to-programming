#include <stdio.h>
#include <stdlib.h>

void tulosta(int taulukko1[], int taulukko2[], int koko);

int main(void)
{
  const int koko = 10;
  int taulukko1[koko], taulukko2[koko], i;
  
  for(i=0; i<koko; i++) {
     do{
        printf("Anna luku: ");
        scanf("%d", &taulukko1[i]);
        }while(-10 > taulukko1[i] || 10 < taulukko1[i]);
        
  }
  
  for(i=0; i<koko; i++){
     taulukko2[i] = taulukko1[(koko-1)-i];
  
}


  
  tulosta(taulukko1, taulukko2, koko);
  
  
  system("PAUSE");	
  return 0;
}

void tulosta(int taulukko1[], int taulukko2[], int koko){
   int i;
   printf("%13s%13s\n", "Alkuperainen", "Kaanteinen");
   for(i=0; i<koko; i++){
     printf("%13d%13d\n", taulukko1[i], taulukko2[i]);
}
}
