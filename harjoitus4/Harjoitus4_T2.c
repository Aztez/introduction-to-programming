#include <stdio.h>
#include <stdlib.h>

double korotaPotenssiin (int luku, int potenssi);

int main(void)
{ int lukupotenssi, luku, potenssi;
  
  
  printf("Syota luku: ");
  scanf("%d", &luku);
  printf("Syota potenssi: ");
  scanf("%d", &potenssi);
  
  lukupotenssi = korotaPotenssiin(luku, potenssi);
  
  printf("%d potenssiin %d on %d\n", luku, potenssi, lukupotenssi);
  
  
  
  system("PAUSE");	
  return 0;
}

double korotaPotenssiin(int luku, int potenssi) {
       int i, tulo = 1;
       for (i = 0; i < potenssi; i++) 
       tulo = tulo * luku;     
         
  return tulo;
}
