#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
    float a,b,t;
    char choice;
  
    
   printf("Enter two num:");
  scanf("%f,%'f",&a,&b);    
 
    
         printf("\nA. Addition");
         printf("\nB. Subtraction");
         printf("\nC. Multiplication");
         printf("\nD. Division\n");
         
         scanf("\n%s",&choice);
         
         choice = toupper(choice);
      
        switch(choice){
 
     case 'A':
     t = a + b;
     printf("%.f + %.f = %.f",a,b,t);
    break;
   
    case 'B':
     t = a - b;
     printf("%.f - %.f = %.f",a,b,t);
    break;

     
    case 'C':
    t = a * b;
     printf("%.f * %.f = %.f",a,b,t);
     break;
     
    case 'D':
     t = a / b;
     printf("%.f / %.f = %.f",a,b,t);
     break;
     
    default:;
    printf("eyyy");
  
}
     
     
     
    return 0;
}