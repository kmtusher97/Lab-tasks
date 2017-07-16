#include <iostream>
#include <iomanip>
using namespace std;

int n, frstyr[100][8], scndyr[100][8], ttl[100][8];

void addUp() {
        for(int i=1; i<=n; i++) {
                int total = 0;
                for(int j=1; j<=6; j++) {
                        ttl[i][j] = frstyr[i][j] + scndyr[i][j];
                        total += ttl[i][j];
                }
                ttl[i][7] = total;
        }
}

void dividr() {
        for(int i=0; i<91; i++) {
                if( i%13 == 0 ) cout << "+";
                cout << "-";
        }
        cout << "+" << endl;
}

int main() {
        while( true ) {
                cout << endl << "Enter the number of students : ";
                cin >> n;
                cout << endl << "Enter the marks of 1st year according to the following subjects ::: " << endl;
                cout << " >> Bengali_1st >> English_1st >> Mathematics_1st >> Physics_1st >> Chemistry_1st >> Biology_1st" << endl;
                for(int i=1; i<=n; i++) {
                        for(int j=1; j<=6; j++) {
                                cin >> frstyr[i][j];
                        }
                }
                cout << endl << "Enter the marks of 2nd year according to the following subjects :::" << endl;
                cout << " >> Bengali_2nd >> English_2nd >> Mathematics_2nd >> Physics_2nd >> Chemistry_2nd >> Biology_2nd" << endl;
                for(int i=1; i<=n; i++) {
                        for(int j=1; j<=6; j++) {
                                cin >> scndyr[i][j];
                        }
                }

                addUp();

                cout << endl << "Total scores of individual subjects :" << endl;
                dividr();
                cout << "|   Bengali   |   English   | Mathematics |   Physics   |  Chemistry  |   Biology   |    Total    |" << endl;
                dividr();
                for(int i=1; i<=n; i++) {
                        cout << "|";
                        for(int j=1; j<=7; j++) {
                                cout <<  "    " << setw(4) << ttl[i][j] << "     |";
                        }
                        cout << endl;
                        dividr();
                }
                int choice;
                cout << endl << "If you want to continue press 1 else 0 to exit ... : ";
                cin >> choice;
                if( choice == 0 ) break;
        }

        return 0;
}
