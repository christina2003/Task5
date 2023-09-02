#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
   //codes to get the initial of countdown
   int countdown;
   printf("Enter the countdown initial:");
   scanf("%d", &countdown);

   //codes to print the countdown with delay 1 second before every number
   for(int i=countdown; i>0; i--){
    printf("%d ",i);
    printf("\n");
    sleep(1);
   }
   printf("Blast off to the moon!\n");
   return 0;
}
