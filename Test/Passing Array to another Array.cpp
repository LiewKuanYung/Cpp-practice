#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <vector>
#include <cmath>
#include <string>
#include <cstring>
using namespace std;

//Variable Definition
const int row = 7;
const int column = 2;

const int BIG_R = 40;
const int BIG_C = 80;

//Prototype
void fillEmpty(string[][column],int);
void display(string alphabet[][column], int);
void fillEmpty2(string wholeAlphabet[][BIG_C], int);
void display(string wholeAlphabet[][BIG_C], int);







int main()
{
/******************************************************
/// User input
******************************************************/

/*
	// Input anchor dot coordinate
	int x;
	int y;
	int changeHeight;

	cout << "\n\nEnter the anchor dot coordinate\n";
	cout << "x axis: ";
	cin >> x;
	cout << "y axis: ";
	cin >> y;
*/

string wholeAlphabet [BIG_R][BIG_C] ;
fillEmpty2(wholeAlphabet, BIG_C) ;


// Alphabet Character
string alphabet [row][column];


//fillEmpty(alphabet, row);
int a = 0;
int b = 0;

             alphabet[ a ][ b ] =   {"   #   "};
             alphabet[ a+1 ][ b ] = {"  # #  "};
             alphabet[ a+2 ][ b ] = {" #   # "};
             alphabet[ a+3 ][ b ] = {"#######"};
             alphabet[ a+4 ][ b ] = {"#     #"};
             alphabet[ a+5 ][ b ] = {"#     #"};
             alphabet[ a+6 ][ b ] = {"#     #"};
             display(alphabet, column);

///Passing the array to another array
for(int count1 = 0; count1 < column ; count1++)
{
    for(int count2 = 0 ; count2 < row ; count2++)
    {
        wholeAlphabet[row][column] = alphabet[row][column];
    }
}


/*
b = 2;
             alphabet[ a ][ b ] =   {"   #   "};
             alphabet[ a+1 ][ b ] = {"  # #  "};
             alphabet[ a+2 ][ b ] = {" #   # "};
             alphabet[ a+3 ][ b ] = {"#######"};
             alphabet[ a+4 ][ b ] = {"#     #"};
             alphabet[ a+5 ][ b ] = {"#     #"};
             alphabet[ a+6 ][ b ] = {"#     #"};

///Passing the array to another array
for(int count1 = 0; count1 < column ; count1++)
{
    for(int count2 = 0 ; count2 < row ; count2++)
    {
        wholeAlphabet[row][column] = alphabet[row][column];
    }
}
*/


///Display
display(wholeAlphabet, BIG_C);

return 0;

}




///Other functions

void fillEmpty(string alphabet[][column], int row)
{
    for( int i = 0; i < row; ++i )
    {
      for( int j = 0; j < column; ++j )
      {
         alphabet[ i ][ j ] = "@";
      }
     }
return;
}

void fillEmpty2(string wholeAlphabet[][BIG_C], int BIG_R)
{
    for( int i = 0; i < BIG_R; ++i )
    {
      for( int j = 0; j < BIG_C; ++j )
      {
         wholeAlphabet[ i ][ j ] = "*";
      }
    }
return;
}

void display(string wholeAlphabet[][BIG_C], int BIG_R)
{
    for( int i = 0; i < BIG_R; ++i )
    {
      for( int j = 0; j < BIG_C; ++j )
      {
         cout << wholeAlphabet[ i ][ j ];
      }
      cout << endl;
    }
return;
}

void display(string alphabet[][column], int row)
{
    for( int i = 0; i < row; ++i )
    {
      for( int j = 0; j < column; ++j )
      {
         cout << alphabet[ i ][ j ];
      }
      cout << endl;
     }
     return;
}






