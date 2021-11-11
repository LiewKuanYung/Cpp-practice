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

bool testPIN(vector<int> &, vector<int> &, const int);

int main()
{
    const int NUM = 7;
    vector<int>pin1 {2,4,1,8,7,9,0};
    vector<int>pin2(pin1);
    vector<int>pin3 {1,2,3,4,5,6,7};


    if(testPIN(pin1, pin1, NUM)) cout << "SUCCESS 2 pins are same";
    else cout << "Error first pin != the other pin" ;

}

bool testPIN(vector<int> &custPIN, vector<int> &databasePIN, const int size)
{
    for(int index =0; index < size; index++)
    {
        if (custPIN[index] != databasePIN[index])
        {
            return false;
        }
    }
    return true;
}

