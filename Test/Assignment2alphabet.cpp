#include <iostream>
#include <cstdlib>      // for the function system()
using namespace std;

void display( char displayBoard[][ 2 ], int row );
void clearScren();
void delay();

int main()
{
  char displayBoard[ 7 ][ 5 ];
  for( int i = 0; i < 10; ++i )
  {
     displayBoard[ 0 ][ 0 ] = ' ';     
     displayBoard[ 0 ][ 1 ] = ' ';
     displayBoard[ 0 ][ 2 ] = ' ';
     displayBoard[ 1 ][ 0 ] = '#';
     displayBoard[ 1 ][ 1 ] = ' ';
     displayBoard[ 1 ][ 2 ] = ' ';          
     displayBoard[ 2 ][ 0 ] = ' ';
     displayBoard[ 2 ][ 1 ] = ' ';
     displayBoard[ 2 ][ 2 ] = ' ';          
     display( displayBoard, 5 );

     displayBoard[ 0 ][ 0 ] = ' ';     
     displayBoard[ 0 ][ 1 ] = ' ';
     displayBoard[ 0 ][ 2 ] = ' ';
     displayBoard[ 1 ][ 0 ] = ' ';
     displayBoard[ 1 ][ 1 ] = '#';
     displayBoard[ 1 ][ 2 ] = ' ';          
     displayBoard[ 2 ][ 0 ] = ' ';
     displayBoard[ 2 ][ 1 ] = ' ';
     displayBoard[ 2 ][ 2 ] = ' ';          
     display( displayBoard, 5 );

     displayBoard[ 0 ][ 0 ] = ' ';     
     displayBoard[ 0 ][ 1 ] = ' ';
     displayBoard[ 0 ][ 2 ] = ' ';
     displayBoard[ 1 ][ 0 ] = ' ';
     displayBoard[ 1 ][ 1 ] = ' ';
     displayBoard[ 1 ][ 2 ] = '#';          
     displayBoard[ 2 ][ 0 ] = ' ';
     displayBoard[ 2 ][ 1 ] = ' ';
     displayBoard[ 2 ][ 2 ] = ' ';          
     display( displayBoard, 5 );
  }
  
  return 0;
}

void display( char displayBoard[][ 5 ], int row )
{
   for( int i = 0; i < row; ++i )
   {
      for( int j = 0; j < 5; ++j )
      {
         cout << displayBoard[ i ][ j ];
      }
      cout << endl;
   }
   delay();
   clearScren();
}

void delay()
{
   for( int i = 0; i < 300000000; ++i )
   { }
}

void clearScren()
{
   system( "cls" );
}
