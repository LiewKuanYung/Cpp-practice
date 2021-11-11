#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#include <cstdlib>
#include <fstream>
using namespace std;

int main()
{
    int lottery[5];
    int maxValue = 10;
    int minValue = 0;

    unsigned seed = time(0);
    srand(seed);
    /*
    lottery[0] = (rand()%(maxValue-minValue+1) + minValue);
    lottery[1] = (rand()%(maxValue-minValue+1) + minValue);
    lottery[2] = (rand()%(maxValue-minValue+1) + minValue);
    lottery[3] = (rand()%(maxValue-minValue+1) + minValue);
    lottery[4] = (rand()%(maxValue-minValue+1) + minValue);
    */

    for(int count = 0; count <5; count++)
    {
        int num = (rand()%(maxValue-minValue+1) + minValue);
        lottery[count] = num;
    }

    int user[5];
    for(int num=0; num<5 ;num++)
    {
        cout <<"Please enter digit number "<<num+1<<" : ";
        cin >> user[num];
        while(user[num]<0 || user[num]>10)
        {
            cout <<"Invalid number entered, please enter again\n"
                 <<"Reminder: Only 1 digit allowed\n"
                 <<"Please enter digit number "<<num+1<<" : ";
            cin >> user[num];
        }
    }

    int x=0;
    for(int num=0; num<5; num++)
    {
        if(lottery[num] == user[num])
        {
            x++;
        }
    }

    bool win = true;
    for(int num=0; num<5; num++)
    {
        if(lottery[num]!=user[num])
        {
            win = false;
            break;
        }
    }


    if(win)
    {
        cout<<"Congratulation";
    }
    else cout<<"try you luck next time";




    cout <<endl<<"Lottery: ";
    for(int num=0; num<5 ;num++)
    {
        cout<< lottery[num];
    }
    cout <<endl<<"User: ";
    for(int num=0; num<5 ;num++)
    {
        cout<< user[num];
    }

    if(x == 0)cout <<endl<<"No matching number";
    else if(x == 1)cout <<endl<<"There are "<<x<<" matching number";
    else cout <<endl<<"There are "<<x<<" matching number";

    if(x !=0)
    cout <<"(element ";
    for(int num=0; num<5; num++)
    {
        if(lottery[num] == user[num])
        {
            cout << user[num] <<" ";
        }
    }
    cout <<")";
    return 0;
}
