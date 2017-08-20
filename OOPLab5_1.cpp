#include <iostream>
#include <cstring>
using namespace std;

class account {
    private:
        int acc_no, age;
        string name;
        float balance;
        static float total_money;
    public:
        account() {  /// constructor & initializer
            acc_no = -1, age = -1, name = "", balance = 0;
            cout << "created\n";
        }
        void get_info() {
            float blnce;
            cout << "Account No: "; cin >> acc_no;
            cin.ignore();
            cout << "Name: "; getline(cin, name);
            cout << "Age: "; cin >> age;
            cout << "Initial Balance: "; cin >> blnce;
            balance += blnce;
            total_money += blnce;
            cout << endl;
        }
        void display_info() {
            cout << "Account No: " << acc_no << endl;
            cout << "Name: " << name << endl;
            cout << "Age: " << age << endl;
            cout << "Current Balance: " << balance << endl << endl;
        }
        float add_amount( float amount ) {
            total_money += amount;
            return balance+=amount;
        }
        float subtrct_amount( float amount ) {
            total_money -= amount;
            return balance-=amount;
        }
        void deposit( float amount ) {
            balance = add_amount( amount );
        }
        void withdraw( float amount ) {
            balance = subtrct_amount( amount );
        }
        float display_balace() {
            return balance;
        }
        float display_total_money() {
            return total_money;
        }
        ~account() {
            cout << "Destroyed\n";
        }
};

float account :: total_money = 0;

int main() {
    account ac[2];
    for(int i=0; i<2; ++i) {
        ac[i].get_info();
    }
    cout << "\nAccountInformations after the accounts've created:\n";
    for(int i=0; i<2; ++i) {
        ac[i].display_info();
    }
    cout << "\nInitial balances:\n";
    cout << "Total balance of 1st account holder: " << ac[0].display_balace() << endl;
    cout << "Total balance of 2nd account holder: " << ac[1].display_balace() << endl;
    cout << "*** Total Money = " << ac[1].display_total_money() << endl;
    /// deposits
    ac[0].deposit( 500 );
    ac[1].deposit( 1000 );
    cout << "\nBalances after deposits:\n";
    cout << "Total balance of 1st account holder: " << ac[0].display_balace() << endl;
    cout << "Total balance of 2nd account holder: " << ac[1].display_balace() << endl;
    cout << "*** Total Money = " << ac[1].display_total_money() << endl;
    /// Drawings
    ac[0].withdraw( 100 );
    ac[1].withdraw( 200 );
    cout << "\nBalances after drawings:\n";
    cout << "Total balance of 1st account holder: " << ac[0].display_balace() << endl;
    cout << "Total balance of 2nd account holder: " << ac[1].display_balace() << endl;
    cout << "*** Total Money = " << ac[1].display_total_money() << endl;
    cout << "\nFinal Info:\n";
    for(int i=0; i<2; ++i) {
        ac[i].display_info();
    }

    return 0;
}
