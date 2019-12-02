#include <stdio.h>
#include <math.h>

double laskePmaksu (double aika);

int main(void){
  double pmaksu1, pmaksu2, pmaksu3, paika1, paika2, paika3;
  
  do {
     printf("Asiakas 1, anna pysakointiaika: ");
     scanf("%lf", &paika1);
 }while(paika1<=0 || paika1>24);
 
  pmaksu1 = laskePmaksu(paika1);
  
    do {
     printf("Asiakas 2, anna pysakointiaika: ");
     scanf("%lf", &paika2);
 }while(paika2<=0 || paika2>24);
 
  pmaksu2 = laskePmaksu(paika2);
  
    do {
     printf("Asiakas 3, anna pysakointiaika: ");
     scanf("%lf", &paika3);
 }while(paika3<=0 || paika3>24);
 
  pmaksu3 = laskePmaksu(paika3);
  
  printf("\nAsikas 1, %.2lf tuntia maksaa %.2lf euroa\nAsikas 2, %.2lf tuntia maksaa %.2lf euroa\nAsikas 3, %.2lf tuntia maksaa %.2lf euroa\n", paika1, pmaksu1, paika2, pmaksu2, paika3, pmaksu3);
  	
  system("PAUSE");	
  return 0;
}

double laskePmaksu(double aika){
   double veloitus = 0.0;
   double fraktio;
       
   if(aika <= 3.0){
      veloitus = 2.0;
         
   }else{
      if(aika <= 19.0){
         veloitus = 2+((aika - 3)*0.5);
      
      }else{
         veloitus = 10;
      }}
      
      return  veloitus;
}
               
