#include <stdio.h>
#include <stdlib.h>

int onkoKarkaus (int vuosi);

int main(void)
{
  int vuosi, onKarkaus;
  
  printf("Syota vuosiluku: ");
  scanf("%d", &vuosi);
  
  if (onkoKarkaus(vuosi))
  printf("Vuosi on karkausvuosi.\n");
  
  else
  printf("Vuosi ei ole karkausvuosi.\n");
  	
  system("PAUSE");	
  return 0;
}

 int onkoKarkaus(int vuosi) {
     if(vuosi %400==0)
        return 1;
     else if(vuosi %100==0)
        return 0;
     else if(vuosi %4==0)
        return 1;
     else
        return 0;
        
}
