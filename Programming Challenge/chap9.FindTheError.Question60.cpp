#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int* getNum()
{
    int wholeNum;
    cout <<"Enter a number: ";
    cin >> wholeNum;

    cout <<endl;
    cout <<"Inside getNum:\n";
    cout <<&wholeNum<<endl;
    cout <<wholeNum<<endl<<endl;

    return &wholeNum;
}



int main()
{
    int *num;

    cout <<"Initial num"<<endl;
    cout << &num <<endl;
    cout << *num <<endl;
    cout << num  <<endl<<endl;

    num = getNum();

    cout << "After returned to num"<<endl;
    cout << *num <<endl;
    cout << num <<endl<<endl;



    return 0;
}
