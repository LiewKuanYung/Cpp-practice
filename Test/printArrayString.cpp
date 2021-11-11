#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <vector>
#include <cmath>
#include <string>
#include <cstring>
using namespace std;

//Variable Definition
const int row = 20;
const int column = 40;

//Prototype
void fillEmpty(string[][column],int);
void display(string[][column],int);



int main()
{
/******************************************************
/// User input
******************************************************/
	// Input anchor dot coordinate
	int x;
	int y;
	int changeHeight;

	cout << "\n\nEnter the anchor dot coordinate\n";
	cout << "x axis: ";
	cin >> x;
	cout << "y axis: ";
	cin >> changeHeight;
	y = row - changeHeight;

    string arrayA [row][column] ;

             fillEmpty(arrayA, row);
             arrayA[ y ][ x ] =   {"   #   "};
             arrayA[ y+1 ][ x ] = {"  # #  "};
             arrayA[ y+2 ][ x ] = {" #   # "};
             arrayA[ y+3 ][ x ] = {"#######"};
             arrayA[ y+4 ][ x ] = {"#     #"};
             arrayA[ y+5 ][ x ] = {"#     #"};
             arrayA[ y+6 ][ x ] = {"#     #"};
             display(arrayA, row);

    return 0;

}

void fillEmpty(string arrayA[][column], int row)
{
    for( int i = 0; i < row; ++i )
    {
      for( int j = 0; j < column; ++j )
      {
         arrayA[ i ][ j ] = "*";
      }
      cout << endl;
     }
     return;
}

void display(string arrayA[][column], int row)
{
    for( int i = 0; i < row; ++i )
    {
      for( int j = 0; j < column; ++j )
      {
         cout << arrayA[ i ][ j ];
      }
      cout << endl;
     }
     return;
}

