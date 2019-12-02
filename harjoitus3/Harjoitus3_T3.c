#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  
  int luku, i=1, kertoma=1;
  
      do{
      printf("Anna luku: ");
      scanf("%d", &luku);
      
      if(luku<1 || luku>13)
         printf("Vaara arvo! ");
         
      }while(luku<1 || luku>13);
         
      while(i <= luku) {
         printf("%d!=%d\n", i, kertoma); 
         i=i+1;
         kertoma=kertoma*i;
    }
    
  system("PAUSE");	
  return 0;
}
