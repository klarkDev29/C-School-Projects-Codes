#include <stdio.h>q

int main () {
	
	int digit,temp,a=0,b=1,sum=0;
	
    printf("enter a number:");
    scanf("%d", &digit);
    
    for(int i=0; i < digit;i++){
    	
    	printf("%d,", a);
    	sum = sum + a;
    	temp= a+b;
    	a=b;
    	b=temp;
    	 
    }
    printf("\nThe Total is: %d",sum);
    if (sum%2==0){
   
    printf("\nThe Sum is: COMPOSITE");
    }
    else{
    printf("\nThe Sum is: PRIME");
   
    }
     printf("\nnice ka");

    
      return 0;
     
}