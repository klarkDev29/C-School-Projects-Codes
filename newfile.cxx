
#include <stdio.h>
int main(){
	int age;
	printf("Enter Your Age: ");
	scanf("%d",&age);
	if(age>=60){
	    printf("This Person is Senior Citizen");
	}
	else if(age>=20 &&
	age<=59){
	    printf("This Person is Adult");
    }
    else if(age>=13 &&
    age<=19){
        printf("This Person is Teenager");
    }
    else if(age>=2 &&
   age<=12){
        printf("This Person is a Child");
    }
    else {
        printf("This Person is Newborn");
    }
    return 0;	
}