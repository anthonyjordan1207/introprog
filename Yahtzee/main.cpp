#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

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

    sort (dice.begin(),dice.end());

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
        if (dice[0] == 1 && dice [4] == 6 && dice[3] == 5 && dice [2] == 3){
            return 0;
        }

        else{
            int z = 0;
            for (int i = 0; i < dice.size(); i++){
                if (dice[i] == dice[i+1]-1){
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


int calcyahtzee (vector<int> dice) {

        if (dice [0] == dice [1] && dice [0] == dice [2] && dice [0] == dice[3] && dice [0] == dice [4]) {
            return 50;

        }
        else {

            return 0;
        }
    }


int calcyahtzeebonus (vector<int> dice) {

if (dice [0] == dice [1] && dice [0] == dice [2] && dice [0] == dice[3] && dice [0] == dice [4]) {
        return 100;

    }


    else {
        return 0;
    }
}



int calcchance(vector<int> dice)
{

        int x = 0;
        for(int i = 0; i < dice.size(); i++)
        {
            x = x + dice[i];
        }
        return x;
    }


int calculateScore (vector<int> dice, int caseVal){
    switch (caseVal) {
    case 1:
        return calcaces(dice);
        break;
    case 2:
        return calctwos(dice);
        break;
    case 3:
        return calcthrees(dice);
        break;
    case 4:
        return calcfours(dice);
        break;
    case 5:
        return calcfives(dice);
        break;
    case 6:
        return calcsixes(dice);
        break;
    case 7:
        return calcthreeofakind(dice);
        break;
    case 8:
        return calcfourofakind(dice);
        break;
    case 9:
        return calcfullhouse(dice);
        break;
    case 10:
        return calcsmallstraight(dice);
        break;
    case 11:
        return calclargestraight(dice);
        break;
    case 12:
        return calcyahtzee(dice);
        break;
    case 13:
        return calcchance(dice);
        break;
    case 14:
        return calcyahtzeebonus(dice);
        break;
    }

    return 0;
}

int upperTotal(vector<int> scores){
    int x;
     for (int i = 0; i < 6; i++){
         x += scores[i];
     }
     return x;
}

int main(){
    int total = 0;
    vector <int> scores {0,0,0,0,0,0,0,0,0,0,0,0,0};
    bool bonusDone = false;
    vector <bool> usedscores {false, false, false, false, false, false, false, false, false, false, false, false, false};

    srand(time(0));

    int caseVal;

    for (int i = 0; i < 13; i++){

        vector <int> dice{rand() %6+1,rand() %6+1,rand() %6+1,rand() %6+1,rand() %6+1};
        cout << "Dice: ";
        cout << dice[0] << "   ";
        cout << dice[1] << "   ";
        cout << dice[2] << "   ";
        cout << dice[3] << "   ";
        cout << dice[4] << endl;

        for (int i = 0; i < 2; i++){

            cout << "Which die would you like to reroll? (1-5)(0 when done)" << endl;
            int x;
            cin >> x;

            while (x > 0){
                dice[x-1] = rand() %6+1;
                cin >> x;
            }

            cout << dice[0] << "   ";
            cout << dice[1] << "   ";
            cout << dice[2] << "   ";
            cout << dice[3] << "   ";
            cout << dice[4] << endl;
        }
    if (upperTotal(vector<int> (scores)) >= 63){

        }

        cout << "Which rule?(1 = 1's, 2 = 2's, 3 = 3's, 4 = 4's, 5 = 5's, 6 = 6's, 7 = 3 of a kind, 8 = 4 of a kind, 9 = full house, 10 = small straight, 11 = large straight, 12 = yahtzee, 13 = chance, 14 = yahtzee bonus)" << endl;
        cin >> caseVal;
        while (usedscores[caseVal - 1] == true){
            cout << "This rule was already used, please choose a different rule " << endl;
            cin >> caseVal;
        }

        cout << calculateScore (dice, caseVal) << endl;
        scores [caseVal - 1] = calculateScore(dice, caseVal);
        total += calculateScore(dice,caseVal);
        usedscores [caseVal - 1] = true;
        if (bonusDone == false && upperTotal(scores) >= 63){
            total += 35;
            bonusDone = true;
        }

        cout << "So far you have: " << total << " points" << endl;
    }
    cout << "Your total score is: " << total << endl;
}
