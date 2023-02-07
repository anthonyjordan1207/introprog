#include <iostream>

using namespace std;

int main()
{
   cout << "What's your favorite word??? " << endl;

     string x;

   cin >> x;

   int y = x.length();
   int n;

   for (int n = 0; y < n; n++)
   cout << "*";

   cout << "****" << y << endl;
   cout << "* " << x << " *" << endl;
   cout << "****" << y << endl;

}

