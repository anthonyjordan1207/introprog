#include <iostream>

using namespace std;


int main()
{
   double x;
   double y;
   double n;
   double a;
   int q;
   int w;
   int e;
   int r;
   int t;
   int u;
   int qi;
   int wi;
   int ei;
   int ri;
   int ti;
   int ui;
   int newq;
   int neww;
   int newe;
   int newr;
   int newt;
   int newu;
   int newquarter;
   int newdime;
   int newnickel;
   int newpenny;
   int quarteri;
   int dimei;
   int nickeli;
   int pennyi;
   double quarter;
   double dime;
   double nickel;
   double penny;

   q = 100;
   w = 50;
   e = 20;
   r = 10;
   t = 5;
   u = 1;
   quarter = 0.25;
   dime = 0.1;
   nickel = 0.05;
   penny = 0.01;

    cout << "How much money do they owe? ";

    cin >> x;

    cout << "How much money did they give you? ";

    cin >> y;

    n = x - y;
    a = y - x;
    qi = a/q;
    newq = a-qi;
    wi = qi/w;
    neww = newq-wi;
    ei = wi/e;
    newe = neww-ei;
    ri = ei/r;
    newr = newe-ri;
    ti = ri/t;
    newt = newr-ti;
    ui = ti/u;
    newu = newt-ui;
    quarteri = ui/quarter;
    newquarter = newu-quarteri;
    dimei = quarteri/dime;
    newdime = newquarter-dimei;
    nickeli = dimei/nickel;
    newnickel = newdime-nickeli;
    pennyi= nickeli/penny;
    newpenny = newnickel-pennyi;

    if (y > x){

        a = y - x;
        qi = a/q;
        newq = a-qi;
        wi = qi/w;
        neww = newq-wi;
        ei = wi/e;
        newe = neww-ei;
        ri = ei/r;
        newr = newe-ri;
        ti = ri/t;
        newt = newr-ti;
        ui = ti/u;
        newu = newt-ui;
        quarteri = ui/quarter;
        newquarter = newu-quarteri;
        dimei = quarteri/dime;
        newdime = newquarter-dimei;
        nickeli = dimei/nickel;
        newnickel = newdime-nickeli;
        pennyi= nickeli/penny;
        newpenny = newnickel-pennyi;

        cout << "You owe " << endl;
        cout << qi << "hundreds" << endl;
        cout << wi << "fifties" << endl;
        cout << ei << "twenties" << endl;
        cout << ri << "tens" << endl;
        cout << ti << "fives" << endl;
        cout << ui << "ones" << endl;
        cout << quarteri << "quarters" << endl;
        cout << dimei << "dimes" << endl;
        cout << nickeli << "nickels" << endl;
        cout << pennyi << "pennies" << endl;
    }

    if (y < x){
        cout << "They owe " << n << endl;
    }
    if (y == x) {
        cout << "They paid the right amount!!" << endl;
    }

}
