#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include<bits/stdc++.h>
using namespace std;

///Tic Tac Toe game


void display(char[][5]);

int main()
{
/****************************************
/Board initialization
*****************************************/

    char board[5][5];
    for(int row=0; row<5; row++)
    {
        for(int col=0; col<5; col++)
        board[row][col] = ' ';
    }
    for(int row=0; row<5; row+=2)
    {
        for(int col=1; col<5; col+=2)
        board[row][col] = '|';
    }
    for(int row=0; row<5; row+=2)
    {
        for(int col=1; col<5; col+=2)
        board[row][col] = '|';
    }
    for(int row=1; row<5; row+=2)
    {
        for(int col=0; col<5; col++)
        board[row][col] = '-';
    }

/****************************************
/Game start
*****************************************/

    int x;
    int y;

}



void display(char gameBoard[][5])
{
    for(int row=0; row<5; row++)
    {
        for(int col=0; col<5; col++)
        {cout << board[row][col];
        }cout << endl;
    }

}
