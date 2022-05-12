#include <stdio.h>
#include <stdlib.h>
#include<time.h>
 
int main(void)
{
    // Use current time as seed for random generator
    srand(time(0));
    for(int i = 0; i<5; i++)
        printf(" %d ",  rand()%4);  //限制隨機數範圍在0-3之間(不包含4)
   
    return 0;
}