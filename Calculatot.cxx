#include <stdio.h>

 int main(){
   int modulu;
  int a,b,sum,divide,minus,multiply;
printf("Enter number (a,b)", a,b);
  scanf("%d, %d",&a, &b);
   sum = (a + b);
   minus = (a - b);
   multiply = (a * b);
   divide = (a / b);
   modulu = (a % b);
 
 printf("The sum is %.1d\n", sum);
 printf("The minus is %.1d\n", minus);
 printf("The multiply is %.1d\n", multiply);
 printf("The division is %.1d\n", divide);
 printf("The modulu is %d", modulu);
 

  return 0;
 }