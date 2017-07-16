#include <iostream>
#include <iomanip>
using namespace std;

double tx_clcltr( double x ) {
        if( x > 5000 ) return (x*0.15);
        if( x > 2000 ) return (x*0.1);
        return (x*0.05);
}

double dscunt_clcltr( double x ) {
        if( x > 10000 ) return (x*0.15);
        if( x > 5000 ) return (x*0.1);
        if( x > 1000 ) return (x*0.05);
        return 0;
}

int main() {
        cout << fixed << setprecision(3);
        double pric, tx, dscunt, pymnt;
        int choice;
        while( true ) {
                cout << "Enter the price : ";
                cin >> pric;
                tx = tx_clcltr( pric );
                dscunt = dscunt_clcltr( pric );
                pymnt = pric + tx - dscunt;
                cout << "Tax      :  " << setw(7) << tx << " TK" << endl;
                cout << "Discount :  " << setw(7) << dscunt << " TK" << endl;
                cout << "To pay   :  " << setw(7) << pymnt << " TK" << endl;
                cout << endl << "If you want to continue press 1 else 0 to exit ... : ";
                cin >> choice;
                if( choice == 0 ) break;
        }

        return 0;
}
