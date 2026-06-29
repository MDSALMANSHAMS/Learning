// #include <iostream>
// using namespace std;
// int main()
// {
//     int x = 101;
//     string y = to_string(x);

//     string z = {};
//     for (int i = y.size() - 1; i >= 0; i--)
//     {
//         z = z + y[i];
//     }
//     int a = stoi(z);
//     if (a == x)
//     {
//         cout << "palindrom";
//     }
//     else
//     {
//         cout << "not palindrom";
//     };
// }

#include <iostream>
using namespace std;

int main(){
    int a = 10111;
    string a_s = to_string(a);
    bool result = true;

    for (int i=0; i <= (a_s.size()-1)/2; i++){
        cout << i << endl;
        if (a_s[i] != a_s[(a_s.size()-1) - i])
        {
            result = false;
            break;
        }
    }

    cout << result << endl;

    return 0;
}