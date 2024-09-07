#include <stdio.h>

int main(){
    int L, W, Perimeter, Area;
   
   printf("Enter ", L, W);
   scanf("%d,%d",&L, &W);
   
   Perimeter = (L*2 + W*2);
   Area = (L*W);
   
   printf("Perimeter = %d", Perimeter);
   printf("Area = %d", Area);
   
   return 0;
}
   