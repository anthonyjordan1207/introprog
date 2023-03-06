#include <iostream>
#include <vector>
using namespace std;

vector<string> bignamesonly (vector<string> names)
{

    vector<string>bignames;

    for (int i = 0; i < names.size(); i++) {
        if (names[i].size() >= 4) {
            bignames.push_back(names[i]);
        }
    }
    return bignames;
}

int main()

{

    vector <string> namepeople {"bob", "bobbert", "bobberson", "bo", "bobbie", "boberto"};

    vector <string> bignamepeople = bignamesonly (namepeople);
    vector<string> longnamepeople;
    for (int i = 0; i < longnamepeople.size(); i++) {
        cout << longnamepeople[i] << endl;
    }

}
