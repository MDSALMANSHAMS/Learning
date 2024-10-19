// // method 1

// #include <stdio.h>

// void fn(int i){
//     if (i == 0) return;
//     fn(i-1);
//     printf("%d\n", i);
// }

// int main(){
//     int i;
//     printf("enter i: ");
//     scanf("%d",&i);

//     fn(i);
//     return 0;
// }

// // Method 2

// #include <stdio.h>

// void fn(int a, int i){
//     if (a>i) return;
//     printf("%d\n", a);
//     fn(a+1, i);
// }

// int main(){
//     int i;
//     printf("enter i: ");
//     scanf("%d",&i);

//     fn(1, i);
//     return 0;

// }