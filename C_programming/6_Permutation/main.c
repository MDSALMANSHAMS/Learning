
// #include <stdio.h>
// #include <math.h>

// int fact(int x) {
//     int f = 1;
//     for (int i = 1; i <= x; i++) {
//         f *= i;
//     }
//     return f;
// }

// int ncr(int a, int b){
//     return fact(a)/(fact(b)*fact(a-b));
// }

// int main(){
//     int a;

//     printf("enter n :");
//     scanf("%d",&a);

//     int b;

//     printf("enter r :");
//     scanf("%d",&b);
    
//     int ans = ncr(a, b);
//     printf("%d\n", ans);

// }

#include <stdio.h>

// int fact(int n){
//     if (n==1) return 1;
//     for (int i=0; i<=n; i++){
//         int recAns = i * fact(n-1);
//         return recAns;
//     }

// }


int fact(int x) {
    int f = 1;
    for (int i = 1; i <= x; i++) {
        f *= i;
    }
    return f;
}

void npm(int n, int a) {
    int ans = fact(n)/(fact(a)*fact(n-a));
    printf("%d\n", ans);
    return;
}

int main(){
    int n;
    printf("enter n :");
    scanf("%d",&n);

    int a;
    printf("enter a :");
    scanf("%d",&a);

    npm(n,a);
    return 0;
}