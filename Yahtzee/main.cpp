#include <iostream>
#include <vector>

using namespace std;

int calcchance(vector<int> dice)
{
    int x = 0;
    for(int i = 0; i < dice.size(); i++)
    {
        x = x + dice[i];
    }
    return x;
}

int turns;

int main()
{
    vector <int> dice{1,2,3,4,5};
    cout << calcchance(dice) << endl;
    return 0;
}
