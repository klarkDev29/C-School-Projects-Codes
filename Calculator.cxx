#include <stdio.h>
#include <unistd.h> 

void loadingBar(int delayTime);

int main() {
    int modulu;
    int a, b, sum, divide, difference, product;

    printf("Enter first number: ");
    scanf("%d", &a);
    printf("Enter second number: ");
    scanf("%d", &b);

   
    loadingBar(50000);  
    printf("                                Complete");

    sum = (a + b);
    difference = (a - b);
    product = (a * b);
    divide = (a / b);
    modulu = (a % b);

    printf("\nThe sum is      : %d\n", sum);
    printf("The minus is    : %d\n", difference);
    printf("The multiply is : %d\n", product);
    printf("The division is : %d\n", divide);
    printf("The modulu is   : %d\n", modulu);

    return 0;
}

void loadingBar(int delayTime) {
    int i;
    printf("\nLoading Please Wait: ");
    for (i = 0; i < 30; i++) {
        printf("|");
        fflush(stdout);
        usleep(delayTime);
    }
    printf("\n");
}
