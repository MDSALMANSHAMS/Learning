// WAP to sum of digits of a given number

#include<iostream>
using namespace std;

int main(){
    int n =12345;

    int sum = 0;

    while(n>0){
        int digit = n % 10; 
        n = n / 10; 

        sum = sum + digit;
    }

    cout << sum << endl;
}