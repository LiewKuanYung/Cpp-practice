#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
char k;

do
{
  long long int n, i, m=0, flag=0;

  cout << "Enter the Number to check Prime: ";
  cin >> n;

  m=n/2;

   /***
   m will become int
   if n =9 , n/2 = 4.5 , m = n
   then m = 4
   ***/


  if(m>100) m = 100;
  else;

  for(i = 2; i <= m; i++)
  {
      if(n % i == 0)
      {
          cout<<"Number is not Prime."<<endl;
          flag=1;
          break;
      }
  }
  if (flag==0)
  {cout << "Number is Prime."<<endl;}

  cout << "Do you wish to continue? Y or N: ";
  cin  >> k;
  cout <<endl;


}while( toupper(k) == 'Y');

    return 0;
}
