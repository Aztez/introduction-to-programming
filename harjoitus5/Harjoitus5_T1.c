#include <stdio.h>
#include <math.h>

double laskePmaksu (double aika);
void tulosta(double ajat[], double maksut[], int koko);

int main(void){
  const int koko=10;
  double ajat[koko];
  double maksut[koko];
  int i=0;
  
  for(i=0; i<koko; i++){
  
  do {
     printf("Anna aika: ");
     scanf("%lf", &ajat [i]);
 }while(0>ajat[i] || 24<ajat[i]);
 
} 
  for(i=0; i<koko; i++){
     maksut[i] = laskePmaksu(ajat[i]);
}
  tulosta(ajat, maksut, koko);
  	
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

void tulosta(double ajat[], double maksut[], int koko){
   int i;
   printf("%10s%10s%10s\n", "Asiakas", "Tunnit", "Veloitus");
   for(i=0; i<koko; i++){
   printf("%10d%10.2lf%10.2lf\n", (i+1), ajat[i], maksut[i]);
}

}            
