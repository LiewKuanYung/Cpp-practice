#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <cmath>
#include <string>
#include <fstream>
using namespace std;

int main()
{
/*    char arrayName[7][6];

    for(int i = 0 ; i<7; ++i)
    {
        for(int j = 0; j<6; ++j)
        {
            arrayName[i][j]='*';
        }
    }

    for(int i = 0 ; i<7; ++i)
    {
        for(int j = 0; j<70; ++j)
        {
            cout << arrayName[i][j];
        }
        cout << endl << endl;
    }
*/

char arrayName[2][7][6];
for(int k = 0; k<2 ; ++k)
{
    for(int i = 0 ; i<7; ++i)
    {
        for(int j = 0; j<6; ++j)
        {
            arrayName[k][i][j]='*';
        }
    }
}

for(int k = 0; k<2 ; ++k)
{
    for(int i = 0 ; i<7; ++i)
    {
        for(int j = 0; j<6; ++j)
        {
            cout << arrayName[k][i][j];
        }cout << endl;
    }
}


    return 0;
}
