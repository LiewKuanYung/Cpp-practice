/**********|**********|**********|
Program: main.cpp
Course: Programming Fundamentals (TCP1101)
Year: 2019/20 Trimester 1
Name: Liew Kuan Yung
**********|**********|**********/


#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <cmath>
#include <string>
#include <fstream>
using namespace std;

//Prototype
void delay(int);
void clearScreen();
void emptyBackground(char[][6]);
void setRotation(char[][6], char[][7], string);
void setCharacter(char[], char[][6], int, char);

//Background character
char backChar = ' ';

int main()
{
/************************************************************
//Input file
************************************************************/

    //open file
    fstream inputFile;                      /**Edit your file name at here   **/
    inputFile.open("user_input4.txt");      /**user_input1,2,3,4 available   **/

    if(!inputFile.is_open())
    {cout<<"invalid input file ";return 0;}

    char drawingChar;     //Drawing Character
    int speed;            //Refresh cycle
    int timeLapse;        //Number of refresh cycle
    int flashShow;        //number of flashShow
    string phraseInput;   //user input
    int ianchorX;         //Anchor Dot
    int ianchorY;
    int ihorizontalSize;  //Board size
    int iverticalSize;
    string direction;     //Movement direction
    char wrapping;        //Wrapping effect
    string rotation;      //rot90 , rot-90, mr, non

    //Get input from file
    inputFile.get(drawingChar);
    inputFile >> speed;
    speed = 11 - speed;
    inputFile >> timeLapse;
    inputFile >> flashShow;

    //for different phrases input
    string stringText[flashShow];
    for(int num=0; num<flashShow; ++num)
    {
        if(num==0)inputFile.ignore();
        getline(inputFile,phraseInput,'\n');
        stringText[num]=phraseInput;    //store into string text array
    }

    inputFile >> ianchorX >> ianchorY;
    inputFile >> ihorizontalSize >> iverticalSize;
    inputFile >> direction;
    inputFile >> wrapping;
    inputFile >> rotation;


    //Find the largest size of phrase and its size
    int largest = stringText[0].size();
    if (flashShow>1)
    {
        for(int num=1; num<flashShow; ++num)
        {if(stringText[num].size()>largest)
        largest = stringText[num].size();}
    }

    //copy string text into char text array
    char charText[largest];
    stringText[0].copy(charText,largest);

    ///Checking validation of input file
    for(int num=0;num<flashShow;++num)
    {if(stringText[num].size()>25){cout<<"size of phrase "<<num<<" error"; return 0;}}
    if(speed<1 || speed>10){cout<<"speed error"; return 0;}
    else if(timeLapse<=0){cout<<"time lapse error"; return 0;}
    else if(ianchorX<0 || ianchorY<0){cout<<"anchor dot error"; return 0;}
    else if(ihorizontalSize<=0 || iverticalSize<=0){cout<<"board size error"; return 0;}
    else if(ianchorX>=ihorizontalSize || ianchorY>=iverticalSize){cout<<"anchor dot does not match board size"; return 0;}
    else if(direction!="st" && direction!="lr" && direction!="rl" && direction!="ud" && direction!="du"){cout<<"direction error"; return 0;}
    else if(wrapping!='Y' && wrapping!='N'){cout<<"wrapping error"; return 0;}
    else if(rotation!="rot90" && rotation!="rot-90" && rotation!="mr" && rotation!="non"){cout<<"rotation error"; return 0;}
    else;

    ///Cout input from file for checking
/*    cout <<drawingChar<<" "<<speed<<" "<<timeLapse<<" "<<flashShow<<" "<<stringText[0].size()<<endl;
    for(int count = 0; count < stringText[0].size(); count++) cout << charText[count];
    cout<<endl<<ianchorX<<" "<<ianchorY<<" "<<ihorizontalSize<<" "<<iverticalSize
        <<endl<<direction<<" "<<wrapping<<" "<<rotation<<"\n\n"; return 0;
*/
    //close file
    inputFile.close();

/************************************************************
//Initialization of phrase array
************************************************************/
//set character
//Rotation or mirror (optional)
//pass each character into long phrase array

for(int n=0; n <flashShow; ++n)
{   //when program ran out of scope{}, all data will be deleted, start with new phrase
    {
    int anchorX = ianchorX;               //Anchor Dot
    int anchorY = ianchorY;
    int horizontalSize = ihorizontalSize; //Board size
    int verticalSize = iverticalSize ;
    if(n!=0)stringText[n].copy(charText,largest); //For other phrases

    ///L = Length of the string text
    const int L = stringText[n].size();

    ///Initialize size of columns and rows of phrase array
    int R = 0, C = 0;
    if (rotation=="rot90" || rotation=="rot-90")
    {
        R = 6*L;
        C = 7;
    }
    else if(rotation=="non" || rotation=="mr")
    {
        R = 7;
        C = 6*L;
    }
    else return 0;

    char phrase[R][C];          //combined character arrays
    char eachCharacter[7][6];   //individual character array
    char rotatedChar[6][7];     //rotated character array

    ///Passing each character into phrase array
    ///Pass according to rotation
    if(rotation == "non")
    {
        for(int num = 0, nextPos = 0; num < L ; num++, nextPos += 6)
        {
            emptyBackground(eachCharacter);
            setCharacter(charText,eachCharacter,num,drawingChar);
            for(int r = 0; r <7; r++)
            {
                for( int c = 0; c < 6; c++)
                phrase[r][c+nextPos] = eachCharacter[r][c];
            }
        }
    }
    else if(rotation =="rot90")
    {
        for(int num = 0, nextPos = 0; num < L ; num++, nextPos += 6)
        {
            emptyBackground(eachCharacter);
            setCharacter(charText,eachCharacter,num,drawingChar);
            setRotation(eachCharacter, rotatedChar,rotation);
            for(int r = 0; r <6; r++)
            {
                for( int c = 0; c < 7; c++)
                phrase[r+nextPos][c]=rotatedChar[r][c];
            }
        }
    }
    else if(rotation =="rot-90")
    {
        for(int num = 0, nextPos = 6*(L-1); num < L ; num++, nextPos -= 6)
        {
            emptyBackground(eachCharacter);
            setCharacter(charText,eachCharacter,num,drawingChar);
            setRotation(eachCharacter, rotatedChar, rotation);
            for(int r = 0; r <6; r++)
            {
                for( int c = 0; c < 7; c++)
                phrase[r+nextPos][c]=rotatedChar[r][c];
            }
        }
    }
    else if(rotation =="mr")
    {
        for(int num = 0, nextPos = 0; num < L ; num++, nextPos += 6)
        {
            emptyBackground(eachCharacter);
            setCharacter(charText,eachCharacter,num,drawingChar);
            for(int r = 0; r <7; r++)
            {
                for( int c = 0; c < 6; c++)
                phrase[r][c+nextPos] = eachCharacter[6-r][c];
            }
        }
    }
    else return 0;

    ///Cout phrase array for checking
/*
    //non and mr
    for(int i=0;i<7;i++){for(int j=0;j<L*6;j++)
    {cout << phrase[i][j];}cout << endl;}
    //rot90 and rot-90
    for(int i=0;i<L*6;i++){for(int j=0;j<7;j++)
    {cout << phrase[i][j];}cout << endl;}
    return 0;*/


/************************************************************
//Initialization of display board array
************************************************************/

    int displayX = 0;   //horizontal size
    int displayY = 0;   //vertical size

    //Initialize columns and rows of display board array
    if (rotation=="rot90" || rotation=="rot-90")
    {
        displayX = horizontalSize;
        displayY = verticalSize + 6*L;
    }
    else if(rotation=="non" || rotation=="mr")
    {
        displayX = horizontalSize + 6*L;
        displayY = verticalSize;
    }else return 0;

    //initialize
    char displayBoard[displayY][displayX];

    //empty background avoid garbage value
    for(int rows=0; rows<displayY; ++rows)
    {
        for(int cols=0; cols<displayX; ++cols)
        displayBoard[rows][cols]=backChar;
    }

    ///Checking anchor dot validation
    ///Reinitialize anchor dot (for user friendly)
    if(rotation=="non")
    {
        if(anchorY<6){cout<<"value of anchor Y too small"; return 0;}
        else anchorY = (verticalSize-1)- anchorY;
    }
    else if(rotation=="mr")
    {
        if(anchorY>verticalSize-7){cout<<"value of anchor Y too big"; return 0;}
        else anchorY = (verticalSize-1) - anchorY - 6;
    }
    else if(rotation=="rot90")
    {
        if(anchorX<6){cout<<"value of anchor X too small"; return 0;}
        else anchorX = anchorX - 6;
        anchorY = (verticalSize-1) - anchorY;
    }
    else //rot-90
    {
        if(anchorX>horizontalSize-7){cout<<"value of anchor X too big";return 0;}
        else anchorY = (verticalSize-anchorY) + verticalSize;
    }

    if(rotation!="rot-90")
    {
        for(int rows=0; rows<R; ++rows)
        {
            for(int cols=0; cols<C; ++cols)
            displayBoard[anchorY + rows][anchorX + cols] = phrase[rows][cols];
        }
    }
    else ///rot-90
    {
        int k = 6*L - (anchorY-(verticalSize-1));
        int z = 0;

        for(int rows = 0; rows<R; ++rows)
        {
            for(int cols=0; cols<C; ++cols)
            displayBoard[anchorY + rows - z][anchorX + cols] = phrase[rows][cols];

            if(rows == k)
            {
                anchorY = 0;
                z = rows+1;
            }
            else;
        }
    }

    ///Cout "entire" display board for checking
/*    for(int rows = 0; rows < displayY; rows++)
    {for(int cols = 0; cols < displayX; cols++)
    {cout << displayBoard[rows][cols];}cout << endl;}
    return 0;*/


/************************************************************
//Display => Composition of movements => Delay => ClearScreen
************************************************************/

    if(direction == "st" )//stationary
    {
        for(int rows = 0; rows < verticalSize; ++rows)
        {
            for(int cols = 0; cols < horizontalSize; ++cols)
            {cout << displayBoard[rows][cols];}
            cout << endl;
        }
    }
    else if(direction == "lr") //moving to the right
    {
        char copyArray[verticalSize];

        for(int i=0; i<timeLapse; ++i )
        {
            ///Display
            for(int rows = 0; rows < verticalSize; ++rows)
            {
                for(int cols = 0; cols < horizontalSize; ++cols)
                {cout << displayBoard[rows][cols];}
                cout << endl;
            }

            ///Composition
            for(int rows=0; rows<verticalSize; ++rows)
            copyArray[rows] = displayBoard[rows][0];

            for(int rows=0; rows<verticalSize; ++rows)
            {
                for(int cols = 0; cols < displayX; ++cols)
                displayBoard[rows][cols] = displayBoard[rows][cols+1];
            }

            ///Wrap around effect
            if(wrapping == 'Y')
            {
                for(int rows=0; rows<verticalSize; ++rows)
                displayBoard[rows][displayX-1] = copyArray[rows];
            }
            else
            {
                for(int rows=0; rows<verticalSize; ++rows)
                displayBoard[rows][displayX-1] = backChar;
            }
            delay(speed);
            clearScreen();
        }
    }
    else if(direction == "rl")//moving to the left
    {
        char copyArray[verticalSize];

        for(int i=0; i<timeLapse; ++i )
        {
            ///Display
            for(int rows = 0; rows < verticalSize; ++rows)
            {
                for(int cols = 0; cols < horizontalSize; ++cols)
                {cout << displayBoard[rows][cols];}
                cout << endl;
            }

            ///Composition
            for(int rows=0; rows<verticalSize; ++rows)
            copyArray[rows] = displayBoard[rows][displayX-1];

            for(int rows=0; rows<verticalSize; ++rows)
            {
                for(int cols = displayX-1; cols>=0; --cols)
                displayBoard[rows][cols] = displayBoard[rows][cols-1];
            }

            ///Wrap around effect
            if(wrapping == 'Y')
            {
                for(int rows=0; rows<verticalSize; ++rows)
                displayBoard[rows][0] = copyArray[rows];
            }
            else
            {
                for(int rows=0; rows<verticalSize; ++rows)
                displayBoard[rows][0] = backChar;
            }
            delay(speed);
            clearScreen();
        }
    }
    else if(direction == "ud")//moving down
    {
        char copyArray[horizontalSize];

        for(int i=0; i<timeLapse; ++i )
        {
            ///Display
            for(int rows = 0; rows < verticalSize; ++rows)
            {
                for(int cols = 0; cols < horizontalSize; ++cols)
                {cout << displayBoard[rows][cols];}
                cout << endl;
            }

            ///Composition
            for(int cols=0; cols<horizontalSize; ++cols)
            copyArray[cols] = displayBoard[displayY-1][cols];

            for(int cols=0; cols<horizontalSize; cols++)
            {
                for(int rows = displayY-1; rows>=0; --rows)
                displayBoard[rows][cols] = displayBoard[rows-1][cols];
            }

            ///Wrap around effect
            if(wrapping == 'Y')
            {
                for(int cols=0; cols<horizontalSize; ++cols)
                displayBoard[0][cols] = copyArray[cols];
            }
            else
            {
                for(int cols=0; cols<horizontalSize; ++cols)
                displayBoard[0][cols] = backChar;
            }
            delay(speed);
            clearScreen();
        }
    }
    else if(direction == "du")//moving up
    {
        char copyArray[horizontalSize];

        for(int i=0; i<timeLapse; ++i )
        {
            ///Display
            for(int rows = 0; rows < verticalSize; ++rows)
            {
                for(int cols = 0; cols < horizontalSize; ++cols)
                {cout << displayBoard[rows][cols];}
                cout << endl;
            }

            ///Composition
            for(int cols=0; cols<horizontalSize; ++cols)
            copyArray[cols] = displayBoard[0][cols];

            for(int cols=0; cols<horizontalSize; cols++)
            {
                for(int rows=0; rows<displayY-1; rows++)
                displayBoard[rows][cols] = displayBoard[rows+1][cols];
            }

            ///Wrap around effect
            if(wrapping == 'Y')
            {
                for(int cols=0; cols<horizontalSize; ++cols)
                displayBoard[displayY-1][cols] = copyArray[cols];
            }
            else
            {
                for(int cols=0; cols<horizontalSize; ++cols)
                displayBoard[displayY-1][cols] = backChar;
            }
            delay(speed);
            clearScreen();
        }
    }
    else;
    }

    if(direction == "st")return 0;
    else{cout <<"\n\nNext phrase";delay(300);clearScreen();}
}
    ///End
    cout << "\n\nProgram Ends\nThank you so much and have a nice day\n\n";
    return 0;
}





void delay(int spd)
{
   for( int i = 0; i < spd*30000000 ; ++i );
}

void clearScreen()
{
   system( "cls" );
}

void emptyBackground(char clearBackground[7][6])
{
    for(int rows = 0; rows < 7; rows++)
    {
        for(int cols = 0; cols < 6; cols++)
        {
            clearBackground[rows][cols] = backChar;
        }
    }
}

void setRotation(char character[][6], char rotatingChar[][7], string rot)
{
    if(rot == "rot90")///rotate 90 degree
    {
        for(int rows = 0; rows < 7; ++rows)
        {
            for(int cols = 0; cols < 6; ++cols)
            rotatingChar[cols][6-rows] = character[rows][cols];
        }
    }
    else if(rot == "rot-90")///rotate -90 degree
    {
        for(int rows = 0; rows < 7; ++rows)
        {
            for(int cols = 0; cols < 6; ++cols)
            rotatingChar[5-cols][rows] = character[rows][cols];
        }
    }
}

void setCharacter(char charText[],char character[7][6], int a, char drawChar)
{
    char sign = drawChar;
    if(drawChar==' '){sign = charText[a];} //Inception
    switch(charText[a])
    {
         case 'A':
         case 'a':
         {
             character [0][2] = sign;
             character [1][1] = sign;
             character [1][3] = sign;
             character [2][0] = sign;
             character [2][4] = sign;
             character [3][0] = sign;
             character [3][4] = sign;
             character [4][0] = sign;
             character [4][1] = sign;
             character [4][2] = sign;
             character [4][3] = sign;
             character [4][4] = sign;
             character [5][0] = sign;
             character [5][4] = sign;
             character [6][0] = sign;
             character [6][4] = sign;
             break;
         }
         case 'B':
         case 'b':
         {
             character [0][0] = sign;
             character [0][1] = sign;
             character [0][2] = sign;
             character [0][3] = sign;
             character [1][0] = sign;
             character [1][4] = sign;
             character [2][0] = sign;
             character [2][4] = sign;
             character [3][0] = sign;
             character [3][1] = sign;
             character [3][2] = sign;
             character [3][3] = sign;
             character [4][0] = sign;
             character [4][4] = sign;
             character [5][0] = sign;
             character [5][4] = sign;
             character [6][0] = sign;
             character [6][1] = sign;
             character [6][2] = sign;
             character [6][3] = sign;
             break;
         }
         case 'C':
         case 'c':
         {
             character [0][1] = sign;
             character [0][2] = sign;
             character [0][3] = sign;
             character [1][0] = sign;
             character [1][4] = sign;
             character [2][0] = sign;
             character [3][0] = sign;
             character [4][0] = sign;
             character [5][0] = sign;
             character [5][4] = sign;
             character [5][4] = sign;
             character [6][1] = sign;
             character [6][2] = sign;
             character [6][3] = sign;
             break;
         }
         case 'D':
         case 'd':
         {
             character [0][0] = sign;
             character [0][1] = sign;
             character [0][2] = sign;
             character [0][3] = sign;
             character [1][0] = sign;
             character [1][4] = sign;
             character [2][0] = sign;
             character [2][4] = sign;
             character [3][0] = sign;
             character [3][4] = sign;
             character [4][0] = sign;
             character [4][4] = sign;
             character [5][0] = sign;
             character [5][4] = sign;
             character [6][0] = sign;
             character [6][1] = sign;
             character [6][2] = sign;
             character [6][3] = sign;
             break;
         }
         case 'E':
         case 'e':
         {
             character [0][0] = sign;
             character [0][1] = sign;
             character [0][2] = sign;
             character [0][3] = sign;
             character [0][4] = sign;
             character [1][0] = sign;
             character [2][0] = sign;
             character [3][0] = sign;
             character [3][1] = sign;
             character [3][2] = sign;
             character [3][3] = sign;
             character [4][0] = sign;
             character [5][0] = sign;
             character [6][0] = sign;
             character [6][1] = sign;
             character [6][2] = sign;
             character [6][3] = sign;
             character [6][4] = sign;
             break;
         }
         case 'F':
         case 'f':
         {
             character [0][0] = sign;
             character [0][1] = sign;
             character [0][2] = sign;
             character [0][3] = sign;
             character [0][4] = sign;
             character [1][0] = sign;
             character [2][0] = sign;
             character [3][0] = sign;
             character [3][1] = sign;
             character [3][2] = sign;
             character [3][3] = sign;
             character [4][0] = sign;
             character [5][0] = sign;
             character [6][0] = sign;
             break;
         }
         case 'G':
         case 'g':
         {
             character [0][1] = sign;
             character [0][2] = sign;
             character [0][3] = sign;
             character [0][4] = sign;
             character [1][0] = sign;
             character [2][0] = sign;
             character [3][0] = sign;
             character [4][0] = sign;
             character [4][3] = sign;
             character [4][4] = sign;
             character [5][0] = sign;
             character [5][4] = sign;
             character [6][0] = sign;
             character [6][1] = sign;
             character [6][2] = sign;
             character [6][3] = sign;
             character [6][4] = sign;
             break;
         }
         case 'H':
         case 'h':
         {
             character [0][0] = sign;
             character [0][4] = sign;
             character [1][0] = sign;
             character [1][4] = sign;
             character [2][0] = sign;
             character [2][4] = sign;
             character [3][0] = sign;
             character [3][1] = sign;
             character [3][2] = sign;
             character [3][3] = sign;
             character [3][4] = sign;
             character [4][0] = sign;
             character [4][4] = sign;
             character [5][0] = sign;
             character [5][4] = sign;
             character [6][0] = sign;
             character [6][4] = sign;
             break;
         }
         case 'I':
         case 'i':
         {
             character [0][1] = sign;
             character [0][2] = sign;
             character [0][3] = sign;
             character [1][2] = sign;
             character [2][2] = sign;
             character [3][2] = sign;
             character [4][2] = sign;
             character [5][2] = sign;
             character [6][1] = sign;
             character [6][2] = sign;
             character [6][3] = sign;
             break;
         }
         case 'J':
         case 'j':
         {
             character [0][4] = sign;
             character [1][4] = sign;
             character [2][4] = sign;
             character [3][4] = sign;
             character [4][4] = sign;
             character [5][0] = sign;
             character [5][4] = sign;
             character [6][1] = sign;
             character [6][2] = sign;
             character [6][3] = sign;
             break;
         }
         case 'K':
         case 'k':
         {
             character [0][0] = sign;
             character [0][4] = sign;
             character [1][0] = sign;
             character [1][3] = sign;
             character [2][0] = sign;
             character [2][2] = sign;
             character [3][0] = sign;
             character [3][1] = sign;
             character [4][0] = sign;
             character [4][2] = sign;
             character [5][0] = sign;
             character [5][3] = sign;
             character [6][0] = sign;
             character [6][4] = sign;
             break;
         }
         case 'L':
         case 'l':
         {
             character [0][0] = sign;
             character [1][0] = sign;
             character [2][0] = sign;;
             character [3][0] = sign;
             character [4][0] = sign;;
             character [5][0] = sign;
             character [6][0] = sign;
             character [6][1] = sign;
             character [6][2] = sign;
             character [6][3] = sign;
             character [6][4] = sign;
             break;
         }
         case 'M':
         case 'm':
         {
             character [0][0] = sign;
             character [0][4] = sign;
             character [1][0] = sign;
             character [1][0] = sign;
             character [1][1] = sign;
             character [1][3] = sign;
             character [1][4] = sign;
             character [2][0] = sign;
             character [2][2] = sign;
             character [2][4] = sign;
             character [3][0] = sign;
             character [3][2] = sign;
             character [3][4] = sign;
             character [4][0] = sign;
             character [4][4] = sign;
             character [5][0] = sign;
             character [5][4] = sign;
             character [6][0] = sign;
             character [6][4] = sign;
             break;
         }
         case 'N':
         case 'n':
         {
             character [0][0] = sign;
             character [0][4] = sign;
             character [1][0] = sign;
             character [1][4] = sign;
             character [2][0] = sign;
             character [2][1] = sign;
             character [2][4] = sign;
             character [3][0] = sign;
             character [3][2] = sign;
             character [3][4] = sign;
             character [4][0] = sign;
             character [4][3] = sign;
             character [4][4] = sign;
             character [5][0] = sign;
             character [5][4] = sign;
             character [6][0] = sign;
             character [6][4] = sign;
             break;
         }
         case 'O':
         case 'o':
         {
             character [0][1] = sign;
             character [0][2] = sign;
             character [0][3] = sign;
             character [1][0] = sign;
             character [1][4] = sign;
             character [2][0] = sign;
             character [2][4] = sign;
             character [3][0] = sign;
             character [3][4] = sign;
             character [4][0] = sign;
             character [4][4] = sign;
             character [5][0] = sign;
             character [5][4] = sign;
             character [6][1] = sign;
             character [6][2] = sign;
             character [6][3] = sign;
             break;
         }
         case 'P':
         case 'p':
         {
             character [0][0] = sign;
             character [0][1] = sign;
             character [0][2] = sign;
             character [0][3] = sign;
             character [1][0] = sign;
             character [1][4] = sign;
             character [2][0] = sign;
             character [2][4] = sign;
             character [3][0] = sign;
             character [3][1] = sign;
             character [3][2] = sign;
             character [3][3] = sign;
             character [4][0] = sign;
             character [5][0] = sign;
             character [6][0] = sign;
             break;
         }
         case 'Q':
         case 'q':
         {
             character [0][1] = sign;
             character [0][2] = sign;
             character [0][3] = sign;
             character [1][0] = sign;
             character [1][4] = sign;
             character [2][0] = sign;
             character [2][4] = sign;
             character [3][0] = sign;
             character [3][4] = sign;
             character [4][0] = sign;
             character [4][2] = sign;
             character [4][4] = sign;
             character [5][0] = sign;
             character [5][3] = sign;
             character [6][1] = sign;
             character [6][2] = sign;
             character [6][4] = sign;
             break;
         }
         case 'R':
         case 'r':
         {
             character [0][0] = sign;
             character [0][1] = sign;
             character [0][2] = sign;
             character [0][3] = sign;
             character [1][0] = sign;
             character [1][4] = sign;
             character [2][0] = sign;
             character [2][4] = sign;
             character [3][0] = sign;
             character [3][1] = sign;
             character [3][2] = sign;
             character [3][3] = sign;
             character [4][0] = sign;
             character [4][2] = sign;
             character [5][0] = sign;
             character [5][3] = sign;
             character [6][0] = sign;
             character [6][4] = sign;
             break;
         }
         case 'S':
         case 's':
         {
             character [0][1] = sign;
             character [0][2] = sign;
             character [0][3] = sign;
             character [1][0] = sign;
             character [1][4] = sign;
             character [2][0] = sign;
             character [3][1] = sign;
             character [3][2] = sign;
             character [3][3] = sign;
             character [4][4] = sign;
             character [5][0] = sign;
             character [5][4] = sign;
             character [6][1] = sign;
             character [6][2] = sign;
             character [6][3] = sign;
             break;
         }
         case 'T':
         case 't':
         {
             character [0][0] = sign;
             character [0][1] = sign;
             character [0][2] = sign;
             character [0][3] = sign;
             character [0][4] = sign;
             character [1][2] = sign;
             character [2][2] = sign;
             character [3][2] = sign;
             character [4][2] = sign;
             character [5][2] = sign;
             character [6][2] = sign;
             break;
         }
         case 'U':
         case 'u':
         {
             character [0][0] = sign;
             character [0][4] = sign;
             character [1][0] = sign;
             character [1][4] = sign;
             character [2][0] = sign;
             character [2][4] = sign;
             character [3][0] = sign;
             character [3][4] = sign;
             character [4][0] = sign;
             character [4][4] = sign;
             character [5][0] = sign;
             character [5][4] = sign;
             character [6][1] = sign;
             character [6][2] = sign;
             character [6][3] = sign;
             break;
         }
         case 'V':
         case 'v':
         {
             character [0][0] = sign;
             character [0][4] = sign;
             character [1][0] = sign;
             character [1][4] = sign;
             character [2][0] = sign;
             character [2][4] = sign;
             character [3][0] = sign;
             character [3][4] = sign;
             character [4][0] = sign;
             character [4][4] = sign;
             character [5][1] = sign;
             character [5][3] = sign;
             character [6][2] = sign;
             break;
         }
         case 'W':
         case 'w':
         {
             character [0][0] = sign;
             character [0][4] = sign;
             character [1][0] = sign;
             character [1][4] = sign;
             character [2][0] = sign;
             character [2][4] = sign;
             character [3][0] = sign;
             character [3][2] = sign;
             character [3][4] = sign;
             character [4][0] = sign;
             character [4][2] = sign;
             character [4][4] = sign;
             character [5][0] = sign;
             character [5][1] = sign;
             character [5][3] = sign;
             character [5][4] = sign;
             character [6][0] = sign;
             character [6][4] = sign;
             break;
         }
         case 'X':
         case 'x':
         {
             character [0][0] = sign;
             character [0][4] = sign;
             character [1][0] = sign;
             character [1][4] = sign;
             character [2][1] = sign;
             character [2][3] = sign;
             character [3][2] = sign;
             character [4][1] = sign;
             character [4][3] = sign;
             character [5][0] = sign;
             character [5][4] = sign;
             character [6][0] = sign;
             character [6][4] = sign;
             break;
         }
         case 'Y':
         case 'y':
         {
             character [0][0] = sign;
             character [0][4] = sign;
             character [1][0] = sign;
             character [1][4] = sign;
             character [2][1] = sign;
             character [2][3] = sign;
             character [3][2] = sign;
             character [4][2] = sign;
             character [5][2] = sign;
             character [6][2] = sign;
             break;
         }
         case 'Z':
         case 'z':
         {
             character [0][0] = sign;
             character [0][1] = sign;
             character [0][2] = sign;
             character [0][3] = sign;
             character [0][4] = sign;
             character [1][4] = sign;
             character [2][3] = sign;
             character [3][2] = sign;
             character [4][1] = sign;
             character [5][0] = sign;
             character [6][0] = sign;
             character [6][1] = sign;
             character [6][2] = sign;
             character [6][3] = sign;
             character [6][4] = sign;
             break;
         }
         case '0':
         {
             character [0][1] = sign;
             character [0][2] = sign;
             character [0][3] = sign;
             character [1][0] = sign;
             character [1][4] = sign;
             character [2][0] = sign;
             character [2][3] = sign;
             character [2][4] = sign;
             character [3][0] = sign;
             character [3][2] = sign;
             character [3][4] = sign;
             character [4][0] = sign;
             character [4][1] = sign;
             character [4][4] = sign;
             character [5][0] = sign;
             character [5][4] = sign;
             character [6][1] = sign;
             character [6][2] = sign;
             character [6][3] = sign;
             break;
         }
         case '1':
         {
             character [0][2] = sign;
             character [1][1] = sign;
             character [1][2] = sign;
             character [2][2] = sign;
             character [3][2] = sign;
             character [4][2] = sign;
             character [5][2] = sign;
             character [6][1] = sign;
             character [6][2] = sign;
             character [6][3] = sign;
             break;
         }
         case '2':
         {
             character [0][1] = sign;
             character [0][2] = sign;
             character [0][3] = sign;
             character [1][0] = sign;
             character [1][4] = sign;
             character [2][4] = sign;
             character [3][2] = sign;
             character [3][3] = sign;
             character [4][1] = sign;
             character [5][0] = sign;
             character [6][0] = sign;
             character [6][1] = sign;
             character [6][2] = sign;
             character [6][3] = sign;
             character [6][4] = sign;
             break;
         }
         case '3':
         {
             character [0][0] = sign;
             character [0][1] = sign;
             character [0][2] = sign;
             character [0][3] = sign;
             character [0][4] = sign;
             character [1][0] = sign;
             character [1][4] = sign;
             character [2][3] = sign;
             character [3][2] = sign;
             character [3][3] = sign;
             character [4][4] = sign;
             character [5][0] = sign;
             character [5][4] = sign;
             character [6][1] = sign;
             character [6][2] = sign;
             character [6][3] = sign;
             break;
         }
         case '4':
         {
             character [0][3] = sign;
             character [1][2] = sign;
             character [1][3] = sign;
             character [2][1] = sign;
             character [2][3] = sign;
             character [3][0] = sign;
             character [3][3] = sign;
             character [4][0] = sign;
             character [4][1] = sign;
             character [4][2] = sign;
             character [4][3] = sign;
             character [4][4] = sign;
             character [5][3] = sign;
             character [6][3] = sign;
             break;
         }
         case '5':
         {
             character [0][0] = sign;
             character [0][1] = sign;
             character [0][2] = sign;
             character [0][3] = sign;
             character [0][4] = sign;
             character [1][0] = sign;
             character [2][0] = sign;
             character [2][1] = sign;
             character [2][2] = sign;
             character [2][3] = sign;
             character [3][4] = sign;
             character [4][4] = sign;
             character [5][0] = sign;
             character [5][4] = sign;
             character [6][1] = sign;
             character [6][2] = sign;
             character [6][3] = sign;
             break;
         }
         case '6':
         {
             character [0][2] = sign;
             character [0][3] = sign;
             character [0][4] = sign;
             character [1][1] = sign;
             character [2][0] = sign;
             character [3][0] = sign;
             character [3][1] = sign;
             character [3][2] = sign;
             character [3][3] = sign;
             character [4][0] = sign;
             character [4][4] = sign;
             character [5][0] = sign;
             character [5][4] = sign;
             character [6][1] = sign;
             character [6][2] = sign;
             character [6][3] = sign;
             break;
         }
         case '7':
         {
             character [0][0] = sign;
             character [0][1] = sign;
             character [0][2] = sign;
             character [0][3] = sign;
             character [0][4] = sign;
             character [1][3] = sign;
             character [2][2] = sign;
             character [3][1] = sign;
             character [4][0] = sign;
             character [5][0] = sign;
             character [6][0] = sign;
             break;
         }
         case '8':
         {
             character [0][1] = sign;
             character [0][2] = sign;
             character [0][3] = sign;
             character [1][0] = sign;
             character [1][4] = sign;
             character [2][0] = sign;
             character [2][4] = sign;
             character [3][1] = sign;
             character [3][2] = sign;
             character [3][3] = sign;
             character [4][0] = sign;
             character [4][4] = sign;
             character [5][0] = sign;
             character [5][4] = sign;
             character [6][1] = sign;
             character [6][2] = sign;
             character [6][3] = sign;
             break;
         }
         case '9':
         {
             character [0][1] = sign;
             character [0][2] = sign;
             character [0][3] = sign;
             character [1][0] = sign;
             character [1][4] = sign;
             character [2][0] = sign;
             character [2][4] = sign;
             character [3][1] = sign;
             character [3][2] = sign;
             character [3][3] = sign;
             character [3][4] = sign;
             character [4][4] = sign;
             character [5][3] = sign;
             character [6][0] = sign;
             character [6][1] = sign;
             character [6][2] = sign;
             break;
         }
         case ' ':
         {
             break;
         }
     }
}

