#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <vector>
#include <cmath>
#include <string>
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

    // Input string to be printed
    string stringText;

    cout << "Enter the words to be printed (Up to 25 character only): \n";
	getline(cin, stringText);

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

	// Input direction
	int direction;

	cout << "\n\n1.left \n2.Right \n3.Up \n4.Down\n";
	cout << "Enter the direction of movement: ";
	cin >> direction;

	// Input time lapse
	int timeLapse;

	cout << "\n\nEnter the time lapse: ";
	cin >> timeLapse;





	return 0 ;
}
