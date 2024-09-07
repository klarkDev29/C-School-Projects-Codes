#include <stdio.h>

int main() {
    int x, y, z;
    int temp;

    // Input nga number sa user 
    printf("Enter three numbers (x y z): ");
    scanf("%d %d %d", &x, &y, &z);

    // proces sa pag arrange sa x, y, z nga numbers
    if (x < y) {
        temp = x;
        x = y;
        y = temp;
    }
    if (x < z) {
        temp = x;
        x = z;
        z = temp;
    }
    if (y < z) {
        temp = y;
        y = z;
        z = temp;
    }

    // Output sa number nga dako to gamay
    printf("Numbers in descending order: %d %d %d\n", x,y,z);

    return 0;
}
