/* Checks numbers for repeated digits */

#include <stdbool.h>   /* C99 only */

#include <stdio.h>





int main(void)

{

  unsigned char my_array[10];

  unsigned long n;



  for(unsigned char i=0;i<10;my_array[i++]=0);



  printf("Enter a number: ");



  scanf("%ld", &n);



  printf("0 1 2 3 4 5 6 7 8 9 10\n");



 for(;n;my_array[n%10]++,n/=10);



 for(unsigned char i=0;i<10;printf("%d ",my_array[i++]));



  return 0;

}
