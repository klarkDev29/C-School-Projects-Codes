#include <stdio.h>
int main(){
    int age;
    printf("Enter age: ");
    scanf("%d",&age);
    :
    if (age>=60){
        printf("Person is senior");
    }
    else if (age>=20 && age<=59){
        printf("Person is adult");
    }
    else if (age>=13 && age<=19){
        printf("Person is teenager");
    }
    else if (age>=2 && age <=12){
        printf("Person is child");
    }
    else {
        printf("Person is Newborn");
}
  
    return 0;
    }