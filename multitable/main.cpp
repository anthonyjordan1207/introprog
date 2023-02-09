#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
   int c;
   int r;
   cout << "How many columns would you like?" << endl;

   cin >> c;

   cout << "Now, how many rows would you like?";

   cin >> r;

   for (int n = 1; n < c; n++){
    cout << setw(5) << n;

    for (int a = 1; a < r; a++){
    cout << setw(5) << a*n;
   }
    cout << endl;
   }
}
