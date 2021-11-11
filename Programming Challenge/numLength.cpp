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

int main()
{
    long int n;
    cout <<"Enter a umber: ";
    cin  >> n;


    int base = 10;

    unsigned int number_of_digits = 0;

    do {
     ++number_of_digits;
     n /= base;
    } while (n);

    cout << number_of_digits;
}
