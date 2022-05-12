#include <stdio.h>
#include <stdlib.h>
#include<time.h>
 
int main(void){
    // Use current time as seed for random generator
    srand(time(0));
    for(int i = 0; i<5; i++)
        printf(" %d ",    );  //限制隨機數範圍在 "i到51之間" (不包含52)
    return 0;
}