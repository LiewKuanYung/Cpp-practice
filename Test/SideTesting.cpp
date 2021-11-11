#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <vector>
#include <cmath>
#include <string>
using namespace std;

void delay();
void clearScreen();
void display( string testing[5], int row );

int main()
{
   	string stringText;
	char charText[stringText.size() + 1];

	//getting user input
	getline(cin, stringText);

	// now charText store values of stringText in array and char form
	stringText.copy(charText, stringText.size() + 1);

	int number;
	number = stringText.size();

	cout << number;



	return 0;

}

void display( string testing [5], int row )
{
   for( int i = 0; i < row; ++i )
   {
         cout << testing[ i ];
   }
    cout << endl;


}

void delay()
{
   for( int i = 0; i < 300000000; ++i )
   { }
}

void clearScreen()
{
   system( "cls" );
}
