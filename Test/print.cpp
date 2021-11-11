#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <vector>
#include <cmath>
#include <string>
using namespace std;

int main()
{
char s = '#';
char words;

/******************************************************
/// User input
******************************************************/
    // Input string to be printed
    string stringText;

    cout << "Enter the words to be printed (Up to 25 character only): \n";
	getline(cin, stringText);

	// Input anchor dot coordinate
	int x;
	int y;

	cout << "\n\nEnter the anchor dot coordinate\n";
	cout << "x axis: ";
	cin >> x;
	cout << "y axis: ";
	cin >> y;

char Aa[20][40] ;

for( int i = 0; i < 20; ++i )
{
      for( int j = 0; j < 40; ++j )
      {
         Aa[ i ][ j ] = ' ';
      }
      cout << endl;
}

        Aa[x][y+2] = s;
        Aa[x+1][y+1] = s;
        Aa[x+1][y+3] = s;
        Aa[x+2][y] = s;
        Aa[x+2][y+4] = s;
        Aa[x+3][y] = s;
        Aa[x+3][y+4] = s;
        Aa[x+4][y] = s;
        Aa[x+4][y+1] = s;
        Aa[x+4][y+2] = s;
        Aa[x+4][y+3] = s;
        Aa[x+4][y+4] = s;
        Aa[x+5][y] = s;
        Aa[x+5][y+4] = s;
        Aa[x+6][y] = s;
        Aa[x+6][y+4] = s;

for( int i = 0; i < 20; ++i )
{
      for( int j = 0; j < 40; ++j )
      {
         cout << Aa[ i ][ j ];
      }
      cout << endl;
}


    return 0;

}
