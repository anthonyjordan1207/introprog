#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

vector<double> smallest (.3,15,16.6325,1048,.52);


double absolute(double x)
{
    if (x>0){
        return x;
    }
    else {
        return x * -1;
    }
}
double add(double z, double y)
{
    return z + y;
}
double average(double q, double w)
{
    return (q + w)/2;
}
double squareroot(double e)
{
    return sqrt(e);
}
double square(double r)
{
    return r * r;
}
double smallestinvector(smallest)
{
    return min_element(.3,15,16.6325,1048,.52);
}
double avgvector(smallest)
{
    return ((.3 + 15 + 16.6325 + 1048 + .52)/5);
}

int main(){
double x;
double y;
double z;
double q;
double w;
double e;
double r;

            vector<double> smallest (5);
            smallest [1] = .3;
            smallest [2] = 15;
            smallest [3] = 16.6325;
            smallest [4] = 1048;
            smallest [5] = .52;

    cout << "Enter a negative number: ";
    cin >> x;
    cout << "The absolute value of " << x << " is " << absolute(x) << endl;

    cout << "Now enter 2 values: ";
    cin >> y;
    cin >> z;
    cout << y << " + " << z << " = " << add(y,z) << endl;

    cout << "Enter 2 more values: ";
    cin >> q;
    cin >> w;
    cout << "The average of " << q << " and " << w << " is " << average(q,w) << endl;

    cout << "Enter another number: ";
    cin >> e;
    cout << "The square root of " << e << " is " << squareroot(e) << endl;

    cout << "Enter yet another number: ";
    cin >> r;
    cout << r << " squared = " << square(r) << endl;

    cout << "Here's the smallest number in vector " << smallest << endl;
    cout << smallestinvector;

    cout << "Here's the average of that same function " << endl;
    cout << avgvector;

}
