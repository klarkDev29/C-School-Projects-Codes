#include <stdio.h>
#include <unistd.h>

int main(){
    int grades;
    
    printf("Enter Student Grades :'");
    scanf("%d",&grades);
    
    
    if (grades>=90){
        printf("This student is VERY GOOD");
    }
    else if (grades>=60 && grades<=89){
        printf("This student is PASS");
    }
    else if (grades>=40 && grades<=59){
        printf("This student is FAILED");
    }
    else {
        printf("SHIFT NA UYY");
};111q
  
    return 0;
    }