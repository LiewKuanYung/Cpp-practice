#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <vector>
#include <cmath>
#include <string>
#include <cstring>
using namespace std;

///Variable definition
const int row = 20;
const int column = 40;


/// Variable prototype
void delay();
void clearScreen();
//void displayRight( string arrayA[][ column ], int, int x);
void fillEmpty(string arrayA[][column], int);


int main()
{
string arrayA[row][column];


int number;
cout << "Enter time lapse: ";
cin >> number;

for(int y = 0 ; y <= number ; y++ )
{
     int x = 0;

             fillEmpty(arrayA, row);
             arrayA[ y ][ x ] =   {"   #   "};
             arrayA[ y+1 ][ x ] = {"  # #  "};
             arrayA[ y+2 ][ x ] = {" #   # "};
             arrayA[ y+3 ][ x ] = {"#######"};
             arrayA[ y+4 ][ x ] = {"#     #"};
             arrayA[ y+5 ][ x ] = {"#     #"};
             arrayA[ y+6 ][ x ] = {"#     #"};

        //print out individual alphabet
        for( int i = 0; i < row; ++i )
        {
           for( int j = 0; j < column; ++j )
           {
               cout << arrayA[ i ][ j ];
           }
        cout << endl;
        }

delay();
clearScreen();
}


return 0;
}



/**************************************
//Other function                     //
**************************************/

/*
void displayRight( string arrayA[][ column ], int row, int x )
{
int number;
cout << "Enter time lapse: ";
cin >> number;

for( x ; x <= number ; x++ )
{
   for( int i = 0; i < row; ++i )
   {
      for( int j = 0; j < column; ++j )
      {
         cout << arrayA[ i ][ j ];
      }
      cout << endl;
   }

}
delay();
clearScreen();

   return;
}
*/





void delay()
{
   for( int i = 0; i < 3000000000; ++i )
   { }
}

void clearScreen()
{
   system( "cls" );
}

void fillEmpty(string arrayA[][column], int row)
{
    for( int i = 0; i < row; ++i )
    {
      for( int j = 0; j < column; ++j )
      {
         arrayA[ i ][ j ] = "*";
      }
     }
     return;
}
