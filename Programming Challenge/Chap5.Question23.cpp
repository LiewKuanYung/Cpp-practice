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

int main()
{
    int userInput = 0;
    char displayChar = '+';

    cout << "Please enter how many rows you want: ";
    cin  >> userInput;

    for(int count = 1; count <= userInput; count++)
    {
        for(int a = 1; a<=count;a++)
        {cout << displayChar;}


        int b = count;
        cout <<setw(21-count)<<right; //delete the count if you want to change the direction of the right triangle
        for(b; b<=userInput; b++)
        {cout << displayChar;}

        cout << endl;
    }

    return 0;
}
