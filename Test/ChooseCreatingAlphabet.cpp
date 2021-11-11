#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <vector>
#include <cmath>
#include <string>
using namespace std;

//Global Variable Definition
int row = 7;

//Prototype
void delay();
void clearScreen();
//void display(char, int );

int main()
{
/******************************************************
/// User input
******************************************************/

    /// convert the string to array that store as char
	string stringText;
	char charText[stringText.size() + 1];

	//getting user input
	cout << "Please input up to 25 words: ";
	getline(cin, stringText);

	// now charText store values of stringText in array and char form
	stringText.copy(charText, stringText.size() + 1);


    // The width of array = size * [ 5 + 1(blank space) ]
    int width = stringText.size() * 6 ;
    int height = 7;
    char sign = '#' ;
    char character[height][width] ;

// Fill in empty spaces
for( int i = 0; i < height; ++i )
{
    for( int j = 0; j < width; ++j )
    {
        character[ i ][ j ] = ' ';
    }
    cout << endl;
}

/// Loop and print out the words
for(int a = 0, b = 0 ; a < (stringText.size()+1) ; a++, b = b + 6 )
{
    switch(charText[a])
    {
         case 'A':
         case 'a':
         {
             character [0][b+2] = sign;
             character [1][b+1] = sign;
             character [1][b+3] = sign;
             character [2][b] = sign;
             character [2][b+4] = sign;
             character [3][b] = sign;
             character [3][b+4] = sign;
             character [4][b] = sign;
             character [4][b+1] = sign;
             character [4][b+2] = sign;
             character [4][b+3] = sign;
             character [4][b+4] = sign;
             character [5][b] = sign;
             character [5][b+4] = sign;
             character [6][b] = sign;
             character [6][b+4] = sign;
             break;
         }

         case 'B':
         case 'b':
         {
             character [0][b] = sign;
             character [0][b+1] = sign;
             character [0][b+2] = sign;
             character [0][b+3] = sign;
             character [1][b] = sign;
             character [1][b+4] = sign;
             character [2][b] = sign;
             character [2][b+4] = sign;
             character [3][b] = sign;
             character [3][b+1] = sign;
             character [3][b+2] = sign;
             character [3][b+3] = sign;
             character [4][b] = sign;
             character [4][b+4] = sign;
             character [5][b] = sign;
             character [5][b+4] = sign;
             character [6][b] = sign;
             character [6][b+1] = sign;
             character [6][b+2] = sign;
             character [6][b+3] = sign;
             break;
         }

         case 'C':
         case 'c':
         {
             character [0][b+1] = sign;
             character [0][b+2] = sign;
             character [0][b+3] = sign;
             character [1][b] = sign;
             character [1][b+4] = sign;
             character [2][b] = sign;
             character [3][b] = sign;
             character [4][b] = sign;
             character [5][b] = sign;
             character [5][b+4] = sign;
             character [5][b+4] = sign;
             character [6][b+1] = sign;
             character [6][b+2] = sign;
             character [6][b+3] = sign;
             break;
         }

         case ' ':
         {
             break;
         }
     }
}



for( int i = 0; i < height; ++i )
{
    for( int j = 0; j < width; ++j )
    {
        cout << character[ i ][ j ];
    }
    cout << endl;
}

//display(character, height);

return 0;
}

/*
void display( char character[][ width ], int height)
{
   for( int i = 0; i < height; ++i )
   {
      for( int j = 0; j < width; ++j )
      {
         cout << character[ i ][ j ];
      }
      cout << endl;
   }

   return;
}
*/

void delay()
{
   for( int i = 0; i < 300000000; ++i )
   { }
}

void clearScreen()
{
   system( "cls" );
}



