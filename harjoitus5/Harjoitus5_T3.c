#include <stdio.h>
#include <math.h>

void luePisteet(double [][2], int koko);
void tulostaTaulukko(double[][2], int koko);
double laskeEtaisyys(double x1, double x2, double y1, double y2);

int main(void)
{
  const int koko = 10;
  int i, j;
  double pisteet[10][2];
  double etaisyys;
  
  luePisteet(pisteet, koko);
  
  
  for(i=0; i<koko-1; i++) {
  
  etaisyys = etaisyys + laskeEtaisyys(pisteet[i][0], pisteet[i][1], pisteet[i+1][0], pisteet[i+1][1]);
  
}
  
  tulostaTaulukko(pisteet, koko);
  
  system("PAUSE");	
  return 0;
}

void luePisteet(double pisteet[][2], int koko){
   
   int i;
   
   for(i=0; i<koko; i++){
      printf("Anna X: ");
      scanf("%lf", &pisteet[i][0]);
      printf("Anna Y: ");
      scanf("%lf", &pisteet[i][1]);
            
            
   }  
     
}
double laskeEtaisyys(double x1, double x2, double y1, double y2){
       
   double tulos;
   tulos = sqrt (pow((x1-x2),2) + pow((y1-y2),2));
   
   return tulos;

}
void tulostaTaulukko(double pisteet[][2], int koko){
   
   int i;
   printf("%10s%10s%\n", "x-kordinaatti", "y-koordinaatti");
   for (i=0; i<koko; i++){
      printf("%10.2lf%10.2lf%\n", pisteet[i][0], pisteet[i][1]);
       
   }  
}







