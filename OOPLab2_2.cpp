/*
        OOP Lab 2 
        task 2
        c++ program to show unidigit distance numbers ( like 111, 123 etc ) in a given range
*/
#include <iostream>
#include <cmath>
using namespace std;

const int MX = 123456;
bool mark[MX+100];
int ar[MX+100];

bool chk( int x ) {   /// unidigit distance check
        if( x/100 == 0 ) return false;
        int now, lst, dif;
        lst = x%10, x /= 10;
        now = x%10, x /= 10;
        dif = abs(now-lst), lst = now;
        while( x ) {
                now = x%10, x /= 10;
                if( abs(now-lst) != dif ) return false;
                lst = now;
        }
        return true;
}

void precal() {     /// precalculation up to 123456....
        for(int i=0; i<=MX; i++) {
                if( chk( i ) ) mark[i] = true, ar[i] = 1;
        }

        for(int i=1; i<=MX; i++) ar[i] += ar[i-1];
}

int main() {
        precal();
        while( true ) {
                cout << endl << "Enter Range" << endl;
                int a, b;
                cout << "From  : ";
                cin >> a;
                cout << "To    : ";
                cin >> b;
                cout << endl << ar[b]-ar[a-1] << " numbers have same digit distance and they are" << endl;
                for(int i=a; i<=b; i++) {
                        if( mark[i] ) cout << i << ", ";
                }

                int choice;
                cout << endl << endl << "If you want to continue press 1 else press 0 ? ";
                cin >> choice;
                if( choice != 1 ) break;
        }

        return 0;
}
