#include <stdio.h>

void fn(int n){
    if(n==0) return;
    printf("%d\n",n);
    fn(n-1);
}

int main(){
    int n;
    printf("enter n: ");
    scanf("%d",&n);

    fn(n);
    return 0;
}