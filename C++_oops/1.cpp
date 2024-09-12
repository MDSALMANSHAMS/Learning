#include <iostream>
using namespace std;

class Student
{
public:
    string name;
    int roll_no;
};

int main()
{
    Student S1;
    S1.name = "Rohan";
    S1.roll_no = 1;
    cout << S1.name << " - " << S1.roll_no << endl;

    Student *S2 = new Student();
    S2->name = "Achal";
    S2->roll_no = 2;
    cout << S2->name << " - " << S2->roll_no << endl;

    return 0;
}