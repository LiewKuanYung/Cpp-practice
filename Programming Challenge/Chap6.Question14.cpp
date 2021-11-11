#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include<bits/stdc++.h>
using namespace std;

int getDaysInMonth(int);

int main()
{
    int month =-1;
    int day =-1;
    char leapYear;

    cout<<"Is the year a leap year? ";
    cin >> leapYear;

    while(month<1 || month>12)
    {
        cout << "Please enter month: ";
        cin  >> month;
    }

    if(month==1||month==3||month==5||month==7||month==8&&month==10&&month==12)
    {
        while(day<1 || day>31)
        {
            cout << "Please enter day: ";
            cin  >> day;
        }
    }
    else if(month==2)
    {
        if(toupper(leapYear)=='Y')
        {
            while(day<1 || day>29)
            {
                cout << "Please enter day: ";
                cin  >> day;
            }
        }else
        {
            while(day<1 || day>28)
            {
                cout << "Please enter day: ";
                cin  >> day;
            }
        }
    }else
    {
        while(day<1 || day>30)
        {
            cout << "Please enter day: ";
            cin  >> day;
        }
    }

    cout <<leapYear<<endl<<month<<endl<<day;

    /**********
    use the same concept as above
    add to that month


    for(month = 1; month< monthEnteredByUser; month++
    {
        monthDays = getDaysInMonth(month)
        total = total + monthDays;
    }

    lastly total + day

    then print out the final total
    **********/

    return 0;
}

/**********************

int getDaysInMonth(int num)
//can store days of month in array****
return num

************************/
