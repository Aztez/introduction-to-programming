#include <stdio.h>

int onkokarkausvuosi(int vuosi);
int paivienMaara(int kk, int vuosi);

int main(void)
{
  int pvlkm=0, alku, loppu, vuosi, laskuri;
  
  printf("Anna aloitus kk: ");
  scanf("%d", &alku);
  printf("Anna loppu: ");
  scanf("%d", &loppu);
  printf("Anna vuosi: ");
  scanf("%d", &vuosi);
  
  for(laskuri=alku;laskuri <= loppu; laskuri = laskuri+1) {
     pvlkm=pvlkm+paivienMaara(laskuri, vuosi);
     }
     
  printf("Paivien lukumaara %d\n", pvlkm);
  
  system("PAUSE");
  return 0;
}
                           
 int paivienMaara(int kk, int vuosi){
     switch(kk){
       case 1: case 3: case 5: case 7: case 8: case 10: case 12:
              return 31;
              break;
       case 2: if (onkokarkausvuosi(vuosi))
              return 29;
              else return 28;
              break;
       default: return 30;
       }}
       
 int onkokarkausvuosi(int vuosi) {
     if(vuosi %400==0)
        return 1;
     else if(vuosi %100==0)
        return 0;
     else if(vuosi %4==0)
        return 1;
     else
        return 0;
        
}
