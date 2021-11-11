#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <fstream>
#include <bits/stdc++.h>

using namespace std;

int linearSearch(const int arr[], int size, int value)
{
    int index = 0;
    int position = -1;
    bool found = false;

    while (index < size && !found)
    {
        if(arr[index] == value)
        {
            found = true;
            position = index;
        }
         index++;
    }
    return position;
}

int main()
{
    const int account[5]= {5658845,
                           4520125,
                           7895122,
                           8777541,
                           8451277};
    int searchAcc;
    int num;

    do
    {
        cout << "Please enter your acc: ";
        cin >> searchAcc;
        num = searchAcc;
    }while(to_string(num).length() != 7);

    int pos;
    pos = linearSearch(account,5,searchAcc);

    if(pos == -1){cout << "Invalid input";}
    else {cout<< endl << "Valid search with position " << pos + 1;}

    return 0;
}
