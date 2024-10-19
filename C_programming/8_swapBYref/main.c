#include <stdio.h>

void swap(int* x, int* y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main(){
    int x;
    printf("enter x: ");
    scanf("%d",&x);

    int y;
    printf("enter y: ");
    scanf("%d",&y);

    printf("%d %d\n", x, y);

    swap(&x, &y);
    printf("%d %d\n", x, y);

    return 0;
}
