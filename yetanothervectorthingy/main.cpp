#include <iostream>
#include <vector>

using namespace std;

int howMuch(vector <int> numbers, int x)
{
    int z=0;

    for ( int i=0; i < numbers.size(); i++){

        if ( numbers[i] == x ){

            z++;

        }
    }
    return z;
}




int main()
{
    int x;

    vector <int> digits{1,4,27,1,5,15,38,38,2,2,4,3,3,3,3,4,4,1,8,8,7,34,345,76,34,2345,1,2,4,5,5,6,3,2,3,5,6,2,234,5,4,23424,420,420,420,69,69,69,69,69,69,69,69,69,69,2,2,2,2,2,2,2,3,45,65,42,12,24,5,4,3,543,5,436,2,6432,6,4326,43,543,54,35,324,534,5,};

    cout << "What number would you like to look for? ";
    cin >> x;
    cout << "There are " << howMuch(digits, x) << " " <<  x << "'s" << endl;

}
