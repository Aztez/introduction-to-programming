#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  int luku;
  int yhteensa=0;
  int maara=0;
  double keskiarvo;
  
  do{
      
  printf("Syota luku: ");
  scanf("%d", &luku);
  
  if(luku != 0) {
  
  yhteensa = yhteensa + luku;
  maara++;
}
   }while(luku != 0);
  
  keskiarvo = (double)yhteensa / maara;
  
  printf("Lukujen keskiarvo on %.2lf\n", keskiarvo);
  
  system("PAUSE");	
  return 0;
}
