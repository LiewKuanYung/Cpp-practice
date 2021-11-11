#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <vector>
#include <cmath>
#include <string>
using namespace std;


void delay();
void clearScreen();
void display( string arrayA[][7], int row );

int main()
{
/******************************************************
/// User input
******************************************************/

    /// convert the string to array and store as char
	string stringText;
	char charText[stringText.size() + 1];

	//getting user input
	getline(cin, stringText);

	// now charText store values of stringText in array and char form
	stringText.copy(charText, stringText.size() + 1);


/// Loop and print out the words
for(int x = 0 ; x < (stringText.size()+1) ; x++)
{
    switch(charText[x])
    {
         case 'A':
         case 'a':
         {
             string arrayA [6][7];
             arrayA[ 0 ][ 0 ] = {"   #   "};
             arrayA[ 1 ][ 0 ] = {"  # #  "};
             arrayA[ 2 ][ 0 ] = {" #   # "};
             arrayA[ 3 ][ 0 ] = {"#######"};
             arrayA[ 4 ][ 0 ] = {"#     #"};
             arrayA[ 5 ][ 0 ] = {"#     #"};
             arrayA[ 6 ][ 0 ] = {"#     #"};
             display(arrayA,2);
             break;
         }

         case 'B':
         case 'b':
         {
             string arrayB [6][7];
             arrayB[ 0 ][ 0 ] = {"###### "};
             arrayB[ 1 ][ 0 ] = {"#     #"};
             arrayB[ 2 ][ 0 ] = {"#     #"};
             arrayB[ 3 ][ 0 ] = {"###### "};
             arrayB[ 4 ][ 0 ] = {"#     #"};
             arrayB[ 5 ][ 0 ] = {"#     #"};
             arrayB[ 6 ][ 0 ] = {"###### "};
             display(arrayB,2);
             break;
         }

         case 'C':
         case 'c':
         {
             string arrayC [6][7];
             arrayC[ 0 ][ 0 ] = {"  #####"};
             arrayC[ 1 ][ 0 ] = {" #     "};
             arrayC[ 2 ][ 0 ] = {"#      "};
             arrayC[ 3 ][ 0 ] = {"#      "};
             arrayC[ 4 ][ 0 ] = {"#      "};
             arrayC[ 5 ][ 0 ] = {" #     "};
             arrayC[ 6 ][ 0 ] = {"  #####"};
             display(arrayC,2);
             break;
         }

         case ' ':
         {
             string arraySpace[6][7];
             arraySpace[ 0 ][ 0 ] = {" "};
             arraySpace[ 1 ][ 0 ] = {" "};
             arraySpace[ 2 ][ 0 ] = {" "};
             arraySpace[ 3 ][ 0 ] = {" "};
             arraySpace[ 4 ][ 0 ] = {" "};
             arraySpace[ 5 ][ 0 ] = {" "};
             arraySpace[ 6 ][ 0 ] = {" "};
             break;
         }
     }

}

	return 0;

}

void display( string arrayA[][ 7 ], int row )
{
   for( int i = 0; i < row; ++i )
   {
      for( int j = 0; j < 7; ++j )
      {
         cout << arrayA[ i ][ j ];
      }
      cout << endl;
   }

   return;
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

