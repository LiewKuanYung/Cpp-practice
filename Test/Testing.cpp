#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <vector>
#include <cmath>
#include <string>
using namespace std;

void delay();
void clearScreen();

int main()
{
	string words;

	cout << "Please input the words you want to print out\n";
	getline(cin, words);






	return 0;

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
