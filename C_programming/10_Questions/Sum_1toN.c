// method 1

// #include <stdio.h>

// int sum(int n){
//     if (n==1) return 1;
//     for (int i = 0; i<=n; i++){
//         int recAns = n + sum(n-1);
//         return recAns;
//     }
// }

// int main(){
//     int n;
//     printf("enter n: ");
//     scanf("%d",&n);

//     printf("%d\n", sum(n));
//     return 0;
// }

// method 2

// #include <stdio.h>

// int sum(int n){
//     int s = 0;
//     for (int i=0; i<=n; i++){
//         s += i;
//     }
//     return s;
// }

// int main(){
//     int n;
//     printf("enter n: ");
//     scanf("%d",&n);

//     printf("%d\n", sum(n));
//     return 0;
// }

// method 3

// #include <stdio.h>

// void sum1toN(int i, int j){
//     if (i == 0) {
//         printf("%d\n", j);
//         return;
//     }
//     sum1toN(i-1, j+i);
// }

// int main(){
//     int i;
//     printf("enter i: ");
//     scanf("%d",&i);

//     sum1toN(i, 0);
//     return 0;
// }