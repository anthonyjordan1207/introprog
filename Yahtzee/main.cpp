#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int calcaces(vector<int> dice)
{
    int y = 0;
    for(int i = 0; i < dice.size(); i++)
    {
        if ( dice[i] == 1 )
        {
            y = y + dice[i];
        }

    }
    return y;
}

int calctwos(vector<int> dice)
{
    int z = 0;
    for(int i = 0; i < dice.size(); i++)
    {
        if ( dice[i] == 2 )
        {
            z = z + dice[i];
        }

    }
    return z;
}

int calcthrees(vector<int> dice)
{
    int a = 0;
    for(int i = 0; i < dice.size(); i++)
    {
        if ( dice[i] == 3 )
        {
            a = a + dice[i];
        }

    }
    return a;
}

int calcfours(vector<int> dice)
{
    int b = 0;
    for(int i = 0; i < dice.size(); i++)
    {
        if ( dice[i] == 4 )
        {
            b = b + dice[i];
        }

    }
    return b;
}

int calcfives(vector<int> dice)
{
    int c = 0;
    for(int i = 0; i < dice.size(); i++)
    {
        if ( dice[i] == 5 )
        {
            c = c + dice[i];
        }

    }
    return c;
}

int calcsixes(vector<int> dice)
{
    int d = 0;
    for(int i = 0; i < dice.size(); i++)
    {
        if ( dice[i] == 6 )
        {
            d = d + dice[i];
        }

    }
    return d;
}

int calcthreeofakind(vector<int> dice)
{
    sort (dice.begin(),dice.end());

    if (dice[0] == dice [1] && dice [1] == dice [2] && dice [2] != dice[3] && dice [2] != dice [4]){

    int x = 0;
    for(int i = 0; i < dice.size(); i++)
    {
        x = x + dice[i];
    }

    return x;

}
    if (dice[2] != dice [0] && dice [1] == dice [2] && dice [2] == dice[3] && dice [2] != dice [4]){

    int x = 0;
    for(int i = 0; i < dice.size(); i++)
    {
        x = x + dice[i];
    }

    return x;

}
    if (dice[2] != dice [0] && dice [1] != dice [2] && dice [2] == dice[3] && dice [2] == dice [4]){

    int x = 0;
    for(int i = 0; i < dice.size(); i++)
    {
        x = x + dice[i];
    }

    return x;

}
    else {
        return 0;
    }
}

int calcfourofakind (vector<int> dice){
    if (dice [0] != dice [1] && dice [1] == dice [2] && dice [2] == dice [3] && dice [3] == dice [4]){
        int x = 0;
        for(int i = 0; i < dice.size(); i++)
        {
            x = x + dice[i];
        }
        return x;
    }
    else if (dice [4] != dice [3] && dice [3] == dice [2] && dice [2] == dice [1] && dice [1] == dice [0]){
        int x = 0;
        for(int i = 0; i < dice.size(); i++)
        {
            x = x + dice[i];
        }
        return x;
    }
    else {
        return 0;
    }
}

int calcfullhouse (vector<int> dice) {
    sort (dice.begin(),dice.end());

    if (dice [0] != dice [2] || dice [4] != dice [2]){

        if (dice [0] == dice [1] && dice [1] == dice [2] && dice [4] == dice[3]){
            return 25;
        }
        else if (dice [0] == dice[1] && dice [2] == dice[3] && dice [3] == dice [4]){
            return 25;
        }
        else {
            return 0;
        }
    }
    else {
        return 0;
    }
}
int calcsmallstraight (vector<int> dice) {
    sort (dice.begin(),dice.end());
    int z = 0;
    for (int i = 0; i < dice.size(); i++){
        if (dice[i] == dice[i+1] - 1){
            z++;

        }
    }
    if (z >= 3){
        return 30;
    }
    else {
        return 0;
    }
}

int calclargestraight (vector<int> dice) {
    sort (dice.begin(),dice.end());
    if (dice [0] == 1 && dice [4] == 6){
        return 0;
    }

    else if (dice[0] < dice [1] && dice [1] < dice [2] && dice [2] < dice [3] && dice [3] < dice [4]){
        return 40;
    }

    else {
        return 0;
    }
}

int calcyatzee (vector<int> dice) {

    if (dice [0] == dice [1] && dice [0] == dice [2] && dice [0] == dice[3] && dice [0] == dice [4]) {
        return 50;
    }
    else {

        return 0;
    }
}

//int calcyatzeebonus (vector<int> dice) {

//    return 100;

//}

int calcchance(vector<int> dice)
{
    int x = 0;
    for(int i = 0; i < dice.size(); i++)
    {
        x = x + dice[i];
    }
    return x;
}

int main()
{
    vector <int> dice{4,4,2,4,3};


    cout << "Aces " << calcaces(dice) << endl;
    cout << "Twos " << calctwos(dice) << endl;
    cout << "Threes " << calcthrees(dice) << endl;
    cout << "Fours " << calcfours(dice) << endl;
    cout << "Fives " << calcfives(dice) << endl;
    cout << "Sixes " << calcsixes(dice) << endl;
    cout << "3 of a kind " << calcthreeofakind(dice) << endl;
    cout << "4 of a Kind " << calcfourofakind(dice) << endl;
    cout << "Full House " << calcfullhouse(dice) << endl;
    cout << "Small Straight " << calcsmallstraight(dice) << endl;
    cout << "Large Straight " << calclargestraight(dice) << endl;
    cout << "Yatzee " << calcyatzee(dice) << endl;
    //    cout << "Yatzee Bonus " << calcyatzeebonus(dice) << endl;
    cout << "Chance " << calcchance(dice) << endl;
}
