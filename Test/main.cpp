#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <cmath>
#include <string>
using namespace std;

//Global variable
int speed;
const int tempo = 100000000; //speed = speed * tempo, line 98
const char sign = '#';       //used for displayed words
// Display board size
const int h = 20; // height display
const int w = 40; // width display

//Prototype
void delay();
void clearScreen();

int main()
{
/******************************************************
/// User input                                      ///
******************************************************/

/// Input words to be printed out
    string stringText;
    char charText[stringText.size() + 1];

    //getting user input
    cout << "Please input the words you want to display.\n";
    cout << "Valid for a~z, A~Z, 0~9 and space character only\n";
    cout << "limit to 25 words only\n \n";
    cout << "Please input here: ";
    getline(cin, stringText);

    while(stringText.size() > 25)
    {
        cout << "\n\nPlease limit the length of your text\n";
        cout << "Please input up to 25 words: \n";
        getline(cin, stringText);
    }

    // Now charText (array) store values of stringText (string) in other data type: char
    stringText.copy(charText, stringText.size() );


/// Input anchor dot coordinate
	// Anchor dot = ( x , y )
	int x ;
	int y ;

	cout << "\n\nAnchor dot coordinate\n";
	cout << "Range for x: 0~" << w << "\nRange for y: 0~" << h <<endl;
	cout << "x axis: ";
	cin >> x;
	while(x<0 || x>w) //error checking
    {
        cout << "Please enter x-axis ranged in between 0~" << w << ": ";
        cin >> x;
    }

	cout << "y axis: ";
	cin >> y ;

	while(y<0 || y>h) //error checking
    {
        cout << "Please enter y-axix ranged in between 0~" << h << ": ";
        cin >> y;
    }
	y = h - y - 1; // making it user friendly


/// Input direction
    int direction;

	cout << "\n\n1.left\n2.Right\n3.Up\n4.Down\n";
	cout << "Please enter (1, 2 , 3 or 4) for direction of movement: ";
	cin >> direction;

/// Input time lapse
//How many time for the words to move
	int timeLapse;

	cout << "\n\nPlease enter the number of time lapse: ";
	cin >> timeLapse;

/// Input speed of the movement
    int num;

    cout << "\n\nPlease enter the speed of the movement ranged from min 1 to max 10: ";
    cin >> num;
    while(num<0 || num>10)
    {
        cout << "Invalid! Please enter the speed of the movement from min 1 to max 10: ";
        cin >> num;
    }
    num = 10 - num;
    speed = num * tempo ;

/// Clear input screen
    clearScreen();


/******************************************************
/// Initialization                                  ///
******************************************************/

// The width of character array = size * [ 5 + 1(blank space) ]
int width = stringText.size() * 6 ;
int height = 7 ;
char character [height][width] ;

// Fill in empty spaces (garbage value) in character array
for( int i = 0; i < height; ++i )
{
    for( int j = 0; j < width; ++j )
    {
        character[ i ][ j ] = ' ';
    }
}

/// Loop and creating the character words by words
for(int a = 0, b = 0 ; a < stringText.size() ; a++, b = b + 6 )
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
         case 'D':
         case 'd':
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
             character [3][b+4] = sign;
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
         case 'E':
         case 'e':
         {
             character [0][b] = sign;
             character [0][b+1] = sign;
             character [0][b+2] = sign;
             character [0][b+3] = sign;
             character [0][b+4] = sign;
             character [1][b] = sign;
             character [2][b] = sign;
             character [3][b] = sign;
             character [3][b+1] = sign;
             character [3][b+2] = sign;
             character [3][b+3] = sign;
             character [4][b] = sign;
             character [5][b] = sign;
             character [6][b] = sign;
             character [6][b+1] = sign;
             character [6][b+2] = sign;
             character [6][b+3] = sign;
             character [6][b+4] = sign;
             break;
         }
         case 'F':
         case 'f':
         {
             character [0][b] = sign;
             character [0][b+1] = sign;
             character [0][b+2] = sign;
             character [0][b+3] = sign;
             character [0][b+4] = sign;
             character [1][b] = sign;
             character [2][b] = sign;
             character [3][b] = sign;
             character [3][b+1] = sign;
             character [3][b+2] = sign;
             character [3][b+3] = sign;
             character [4][b] = sign;
             character [5][b] = sign;
             character [6][b] = sign;
             break;
         }
         case 'G':
         case 'g':
         {
             character [0][b+1] = sign;
             character [0][b+2] = sign;
             character [0][b+3] = sign;
             character [0][b+4] = sign;
             character [1][b] = sign;
             character [2][b] = sign;
             character [3][b] = sign;
             character [4][b] = sign;
             character [4][b+3] = sign;
             character [4][b+4] = sign;
             character [5][b] = sign;
             character [5][b+4] = sign;
             character [6][b] = sign;
             character [6][b+1] = sign;
             character [6][b+2] = sign;
             character [6][b+3] = sign;
             character [6][b+4] = sign;
             break;
         }
         case 'H':
         case 'h':
         {
             character [0][b] = sign;
             character [0][b+4] = sign;
             character [1][b] = sign;
             character [1][b+4] = sign;
             character [2][b] = sign;
             character [2][b+4] = sign;
             character [3][b] = sign;
             character [3][b+1] = sign;
             character [3][b+2] = sign;
             character [3][b+3] = sign;
             character [3][b+4] = sign;
             character [4][b] = sign;
             character [4][b+4] = sign;
             character [5][b] = sign;
             character [5][b+4] = sign;
             character [6][b] = sign;
             character [6][b+4] = sign;
             break;
         }
         case 'I':
         case 'i':
         {
             character [0][b+1] = sign;
             character [0][b+2] = sign;
             character [0][b+3] = sign;
             character [1][b+2] = sign;
             character [2][b+2] = sign;
             character [3][b+2] = sign;
             character [4][b+2] = sign;
             character [5][b+2] = sign;
             character [6][b+1] = sign;
             character [6][b+2] = sign;
             character [6][b+3] = sign;
             break;
         }
         case 'J':
         case 'j':
         {
             character [0][b+4] = sign;
             character [1][b+4] = sign;
             character [2][b+4] = sign;
             character [3][b+4] = sign;
             character [4][b+4] = sign;
             character [5][b] = sign;
             character [5][b+4] = sign;
             character [6][b+1] = sign;
             character [6][b+2] = sign;
             character [6][b+3] = sign;
             break;
         }
         case 'K':
         case 'k':
         {
             character [0][b] = sign;
             character [0][b+4] = sign;
             character [1][b] = sign;
             character [1][b+3] = sign;
             character [2][b] = sign;
             character [2][b+2] = sign;
             character [3][b] = sign;
             character [3][b+1] = sign;
             character [4][b] = sign;
             character [4][b+2] = sign;
             character [5][b] = sign;
             character [5][b+3] = sign;
             character [6][b] = sign;
             character [6][b+4] = sign;
             break;
         }
         case 'L':
         case 'l':
         {
             character [0][b] = sign;
             character [1][b] = sign;
             character [2][b] = sign;;
             character [3][b] = sign;
             character [4][b] = sign;;
             character [5][b] = sign;
             character [6][b] = sign;
             character [6][b+1] = sign;
             character [6][b+2] = sign;
             character [6][b+3] = sign;
             character [6][b+4] = sign;
             break;
         }
         case 'M':
         case 'm':
         {
             character [0][b] = sign;
             character [0][b+4] = sign;
             character [1][b] = sign;
             character [1][b] = sign;
             character [1][b+1] = sign;
             character [1][b+3] = sign;
             character [1][b+4] = sign;
             character [2][b] = sign;
             character [2][b+2] = sign;
             character [2][b+4] = sign;
             character [3][b] = sign;
             character [3][b+2] = sign;
             character [3][b+4] = sign;
             character [4][b] = sign;
             character [4][b+4] = sign;
             character [5][b] = sign;
             character [5][b+4] = sign;
             character [6][b] = sign;
             character [6][b+4] = sign;
             break;
         }
         case 'N':
         case 'n':
         {
             character [0][b] = sign;
             character [0][b+4] = sign;
             character [1][b] = sign;
             character [1][b+4] = sign;
             character [2][b] = sign;
             character [2][b+1] = sign;
             character [2][b+4] = sign;
             character [3][b] = sign;
             character [3][b+2] = sign;
             character [3][b+4] = sign;
             character [4][b] = sign;
             character [4][b+3] = sign;
             character [4][b+4] = sign;
             character [5][b] = sign;
             character [5][b+4] = sign;
             character [6][b] = sign;
             character [6][b+4] = sign;
             break;
         }
         case 'O':
         case 'o':
         {
             character [0][b+1] = sign;
             character [0][b+2] = sign;
             character [0][b+3] = sign;
             character [1][b] = sign;
             character [1][b+4] = sign;
             character [2][b] = sign;
             character [2][b+4] = sign;
             character [3][b] = sign;
             character [3][b+4] = sign;
             character [4][b] = sign;
             character [4][b+4] = sign;
             character [5][b] = sign;
             character [5][b+4] = sign;
             character [6][b+1] = sign;
             character [6][b+2] = sign;
             character [6][b+3] = sign;
             break;
         }
         case 'P':
         case 'p':
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
             character [5][b] = sign;
             character [6][b] = sign;
             break;
         }
         case 'Q':
         case 'q':
         {
             character [0][b+1] = sign;
             character [0][b+2] = sign;
             character [0][b+3] = sign;
             character [1][b] = sign;
             character [1][b+4] = sign;
             character [2][b] = sign;
             character [2][b+4] = sign;
             character [3][b] = sign;
             character [3][b+4] = sign;
             character [4][b] = sign;
             character [4][b+2] = sign;
             character [4][b+4] = sign;
             character [5][b] = sign;
             character [5][b+3] = sign;
             character [6][b+1] = sign;
             character [6][b+2] = sign;
             character [6][b+4] = sign;
             break;
         }
         case 'R':
         case 'r':
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
             character [4][b+2] = sign;
             character [5][b] = sign;
             character [5][b+3] = sign;
             character [6][b] = sign;
             character [6][b+4] = sign;
             break;
         }
         case 'S':
         case 's':
         {
             character [0][b+1] = sign;
             character [0][b+2] = sign;
             character [0][b+3] = sign;
             character [1][b] = sign;
             character [1][b+4] = sign;
             character [2][b] = sign;
             character [3][b+1] = sign;
             character [3][b+2] = sign;
             character [3][b+3] = sign;
             character [4][b+4] = sign;
             character [5][b] = sign;
             character [5][b+4] = sign;
             character [6][b+1] = sign;
             character [6][b+2] = sign;
             character [6][b+3] = sign;
             break;
         }
         case 'T':
         case 't':
         {
             character [0][b] = sign;
             character [0][b+1] = sign;
             character [0][b+2] = sign;
             character [0][b+3] = sign;
             character [0][b+4] = sign;
             character [1][b+2] = sign;
             character [2][b+2] = sign;
             character [3][b+2] = sign;
             character [4][b+2] = sign;
             character [5][b+2] = sign;
             character [6][b+2] = sign;
             break;
         }
         case 'U':
         case 'u':
         {
             character [0][b] = sign;
             character [0][b+4] = sign;
             character [1][b] = sign;
             character [1][b+4] = sign;
             character [2][b] = sign;
             character [2][b+4] = sign;
             character [3][b] = sign;
             character [3][b+4] = sign;
             character [4][b] = sign;
             character [4][b+4] = sign;
             character [5][b] = sign;
             character [5][b+4] = sign;
             character [6][b+1] = sign;
             character [6][b+2] = sign;
             character [6][b+3] = sign;
             break;
         }
         case 'V':
         case 'v':
         {
             character [0][b] = sign;
             character [0][b+4] = sign;
             character [1][b] = sign;
             character [1][b+4] = sign;
             character [2][b] = sign;
             character [2][b+4] = sign;
             character [3][b] = sign;
             character [3][b+4] = sign;
             character [4][b] = sign;
             character [4][b+4] = sign;
             character [5][b+1] = sign;
             character [5][b+3] = sign;
             character [6][b+2] = sign;
             break;
         }
         case 'W':
         case 'w':
         {
             character [0][b] = sign;
             character [0][b+4] = sign;
             character [1][b] = sign;
             character [1][b+4] = sign;
             character [2][b] = sign;
             character [2][b+4] = sign;
             character [3][b] = sign;
             character [3][b+2] = sign;
             character [3][b+4] = sign;
             character [4][b] = sign;
             character [4][b+2] = sign;
             character [4][b+4] = sign;
             character [5][b] = sign;
             character [5][b+1] = sign;
             character [5][b+3] = sign;
             character [5][b+4] = sign;
             character [6][b] = sign;
             character [6][b+4] = sign;
             break;
         }
         case 'X':
         case 'x':
         {
             character [0][b] = sign;
             character [0][b+4] = sign;
             character [1][b] = sign;
             character [1][b+4] = sign;
             character [2][b+1] = sign;
             character [2][b+3] = sign;
             character [3][b+2] = sign;
             character [4][b+1] = sign;
             character [4][b+3] = sign;
             character [5][b] = sign;
             character [5][b+4] = sign;
             character [6][b] = sign;
             character [6][b+4] = sign;
             break;
         }
         case 'Y':
         case 'y':
         {
             character [0][b] = sign;
             character [0][b+4] = sign;
             character [1][b] = sign;
             character [1][b+4] = sign;
             character [2][b+1] = sign;
             character [2][b+3] = sign;
             character [3][b+2] = sign;
             character [4][b+2] = sign;
             character [5][b+2] = sign;
             character [6][b+2] = sign;
             break;
         }
         case 'Z':
         case 'z':
         {
             character [0][b] = sign;
             character [0][b+1] = sign;
             character [0][b+2] = sign;
             character [0][b+3] = sign;
             character [0][b+4] = sign;
             character [1][b+4] = sign;
             character [2][b+3] = sign;
             character [3][b+2] = sign;
             character [4][b+1] = sign;
             character [5][b] = sign;
             character [6][b] = sign;
             character [6][b+1] = sign;
             character [6][b+2] = sign;
             character [6][b+3] = sign;
             character [6][b+4] = sign;
             break;
         }
         case '0':
         {
             character [0][b+1] = sign;
             character [0][b+2] = sign;
             character [0][b+3] = sign;
             character [1][b] = sign;
             character [1][b+4] = sign;
             character [2][b] = sign;
             character [2][b+3] = sign;
             character [2][b+4] = sign;
             character [3][b] = sign;
             character [3][b+2] = sign;
             character [3][b+4] = sign;
             character [4][b] = sign;
             character [4][b+1] = sign;
             character [4][b+4] = sign;
             character [5][b] = sign;
             character [5][b+4] = sign;
             character [6][b+1] = sign;
             character [6][b+2] = sign;
             character [6][b+3] = sign;
             break;
         }
         case '1':
         {
             character [0][b+2] = sign;
             character [1][b+1] = sign;
             character [1][b+2] = sign;
             character [2][b+2] = sign;
             character [3][b+2] = sign;
             character [4][b+2] = sign;
             character [5][b+2] = sign;
             character [6][b+1] = sign;
             character [6][b+2] = sign;
             character [6][b+3] = sign;
             break;
         }
         case '2':
         {
             character [0][b+1] = sign;
             character [0][b+2] = sign;
             character [0][b+3] = sign;
             character [1][b] = sign;
             character [1][b+4] = sign;
             character [2][b+4] = sign;
             character [3][b+2] = sign;
             character [3][b+3] = sign;
             character [4][b+1] = sign;
             character [5][b] = sign;
             character [6][b] = sign;
             character [6][b+1] = sign;
             character [6][b+2] = sign;
             character [6][b+3] = sign;
             character [6][b+4] = sign;
             break;
         }
         case '3':
         {
             character [0][b] = sign;
             character [0][b+1] = sign;
             character [0][b+2] = sign;
             character [0][b+3] = sign;
             character [0][b+4] = sign;
             character [1][b] = sign;
             character [1][b+4] = sign;
             character [2][b+3] = sign;
             character [3][b+2] = sign;
             character [3][b+3] = sign;
             character [4][b+4] = sign;
             character [5][b] = sign;
             character [5][b+4] = sign;
             character [6][b+1] = sign;
             character [6][b+2] = sign;
             character [6][b+3] = sign;
             break;
         }
         case '4':
         {
             character [0][b+3] = sign;
             character [1][b+2] = sign;
             character [1][b+3] = sign;
             character [2][b+1] = sign;
             character [2][b+3] = sign;
             character [3][b] = sign;
             character [3][b+3] = sign;
             character [4][b] = sign;
             character [4][b+1] = sign;
             character [4][b+2] = sign;
             character [4][b+3] = sign;
             character [4][b+4] = sign;
             character [5][b+3] = sign;
             character [6][b+3] = sign;
             break;
         }
         case '5':
         {
             character [0][b+0] = sign;
             character [0][b+1] = sign;
             character [0][b+2] = sign;
             character [0][b+3] = sign;
             character [0][b+4] = sign;
             character [1][b] = sign;
             character [2][b] = sign;
             character [2][b+1] = sign;
             character [2][b+2] = sign;
             character [2][b+3] = sign;
             character [3][b+4] = sign;
             character [4][b+4] = sign;
             character [5][b] = sign;
             character [5][b+4] = sign;
             character [6][b+1] = sign;
             character [6][b+2] = sign;
             character [6][b+3] = sign;
             break;
         }
         case '6':
         {
             character [0][b+2] = sign;
             character [0][b+3] = sign;
             character [0][b+4] = sign;
             character [1][b+1] = sign;
             character [2][b] = sign;
             character [3][b] = sign;
             character [3][b+1] = sign;
             character [3][b+2] = sign;
             character [3][b+3] = sign;
             character [4][b] = sign;
             character [4][b+4] = sign;
             character [5][b] = sign;
             character [5][b+4] = sign;
             character [6][b+1] = sign;
             character [6][b+2] = sign;
             character [6][b+3] = sign;
             break;
         }
         case '7':
         {
             character [0][b] = sign;
             character [0][b+1] = sign;
             character [0][b+2] = sign;
             character [0][b+3] = sign;
             character [0][b+4] = sign;
             character [1][b+3] = sign;
             character [2][b+2] = sign;
             character [3][b+1] = sign;
             character [4][b] = sign;
             character [5][b] = sign;
             character [6][b] = sign;
             break;
         }
         case '8':
         {
             character [0][b+1] = sign;
             character [0][b+2] = sign;
             character [0][b+3] = sign;
             character [1][b] = sign;
             character [1][b+4] = sign;
             character [2][b] = sign;
             character [2][b+4] = sign;
             character [3][b+1] = sign;
             character [3][b+2] = sign;
             character [3][b+3] = sign;
             character [4][b] = sign;
             character [4][b+4] = sign;
             character [5][b] = sign;
             character [5][b+4] = sign;
             character [6][b+1] = sign;
             character [6][b+2] = sign;
             character [6][b+3] = sign;
             break;
         }
         case '9':
         {
             character [0][b+1] = sign;
             character [0][b+2] = sign;
             character [0][b+3] = sign;
             character [1][b] = sign;
             character [1][b+4] = sign;
             character [2][b] = sign;
             character [2][b+4] = sign;
             character [3][b+1] = sign;
             character [3][b+2] = sign;
             character [3][b+3] = sign;
             character [3][b+4] = sign;
             character [4][b+4] = sign;
             character [5][b+3] = sign;
             character [6][b+0] = sign;
             character [6][b+1] = sign;
             character [6][b+2] = sign;
             break;
         }
         case ' ':
         {
             break;
         }
     }
}

// create background array
int backHeight = 200, backWidth= 400;
char background[backHeight][backWidth];

// Fill in empty spaces (clear garbage value) in background array
for( int i = 0; i < backHeight; ++i )
{
    for( int j = 0; j < backWidth; ++j )
    {
        background[ i ][ j ] = ' ';
    }
}

///Passing character array into background array
for(int yy = 0; yy < height ; yy++)
{
    for(int xx = 0 ; xx < width ; xx++)
    {
        background [ yy + 99 + y][ xx + 149 +x] = character [yy][xx];      // x and y is anchor dot coordinate
        background [ yy + 99 - 20 + y][ xx + 149 +x] = character [yy][xx]; // For wrapping effect for moving up and down
        background [ yy + 99 + 20 + y][ xx + 149 +x] = character [yy][xx]; // For wrapping effect for moving up and down
    }
}


/******************************************************
/// Display                                         ///
******************************************************/

/// Display board size at line 11
// const int h ; // display height
// const int w ; // display width
/// Wrapping effect manipulator
int wrapping = 0;

/// Direction: 1.left 2.Right 3.Up 4.Down
if(direction == 1){ // Left

    for( int horizontal = 0 ; horizontal < timeLapse ; ++horizontal )
    {
        for( int i = 99 ; i < (99+h) ; ++i )
        {
            for( int j = 149; j < (149+w) ; ++j )
            {
                cout << background[ i ][ j + horizontal ];
            }
         cout << endl;
         }
    delay();
    clearScreen();
    }

}else if (direction == 2){ // Right

    for( int horizontal = 0 ; horizontal < timeLapse ; ++horizontal )
    {
        for( int i = 99 ; i < (99+h) ; ++i )
        {
            for( int j = 149; j < (149+w) ; ++j )
            {
                cout << background[ i ][ j - horizontal ];
            }
         cout << endl;
         }
    delay();
    clearScreen();
    }

}else if (direction == 3){ // Up

    for( int vertical = 0 ; vertical < timeLapse ; ++vertical )
    {
        for( int i = 99 ; i < (99+h) ; ++i )
        {
            for( int j = 149; j < (149+w) ; ++j )
            {
                cout << background[ i + vertical + wrapping ][ j ];
            }
         cout << endl;


        }
        if( vertical% 20 == 0 )wrapping = wrapping - 20;
        delay();
        clearScreen();
    }


}else if (direction == 4){ // Down

    for( int vertical = 0 ; vertical < timeLapse ; ++vertical )
    {
        for( int i = 99 ; i < (99+h) ; ++i )
        {
            for( int j = 149; j < (149+w) ; ++j )
            {
                cout << background[ i - vertical + wrapping ][ j ];
            }
         cout << endl;
         }
         if( vertical% 20 == 0 )wrapping = wrapping + 20;
         delay();
         clearScreen();
    }
}else cout << "error404";

return 0;
}

///Other Functions
void delay()
{
   for( int i = 0; i < speed ; ++i ){ }
}

void clearScreen()
{
   system( "cls" );
}
