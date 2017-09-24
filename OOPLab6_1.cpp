#include <iostream>
#include <iomanip>
using namespace std;

class player{
    private:
        int run, jersey;
    public:
        player() {   // constructor
            run = 0;
            jersey = -1;
        }
        void get_player_info() {
            cin >> jersey;
        }
        void display_status() {
            cout << "Jersey No: " << jersey << "\t\t Run: " << run << endl;
        }
        void operator ++ (int) {  // ++ overload
            run++;
        }
        void operator += (int x) { // += overload
            run += x;
        }
        bool operator > (player) const;
};

bool player :: operator > ( player p ) const {  // > overloading
    return ( run > p.run ) ? true : false;
}

void dividr() {
    cout << "///////////////////////////////////////////////////////" << endl;
}

int main() {
    player p1, p2;
    cout << "Enter the jersey numbers of the 3 players" << endl;
    p1.get_player_info();
    p2.get_player_info();
    dividr();
    p1.display_status();
    p2.display_status();
    p1++;
    p2++, p2++;
    dividr();
    p1.display_status();
    p2.display_status();
    dividr();
    if( p1 > p2 ) {
        cout << "Player_1 is greater\n";
    }
    else {
        cout << "Player_2 is greater\n";
    }
    p1 += 6, p2 += 4;
    dividr();
    p1.display_status();
    p2.display_status();
    dividr();
    if( p1 > p2 ) {
        cout << "Player_1 is greater\n";
    }
    else {
        cout << "Player_2 is greater\n";
    }
    dividr();
    return 0;
}
