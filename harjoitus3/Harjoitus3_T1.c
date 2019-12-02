#include <stdio.h>
 
int main()
{
    int x, y, z;
 
    
    do{
    
    printf("Syota sivun pituus: ");
    scanf("%d", &z);
 
    if(z>20 || z<1) {
            printf("Luvun taytyy olla valilta 1-20! ");
    
}
    }while(z>20 || z<1);
    
    for(x=1; x<=z; x++)
    {
        
        for(y=1; y<=z; y++)
        {
            if(x==1 || x==z || y==1 || y==z)
            {
                
                printf("*");
            }
            else
            {
                printf(" ");
            }
        }
 
        
        printf("\n");
    }
    
    
 
 
 
    system("PAUSE");
    return 0;
} 
