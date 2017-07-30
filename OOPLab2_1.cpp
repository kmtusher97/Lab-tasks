/*
        c++ program to calculate CGPA using structure and switch
*/
#include <iostream>
#include <iomanip>
using namespace std;

const int MX = 10;

struct data {
        int indx, mrks;
        double GPA;
        string grd;

        void grdFinder() {
                int x = mrks/10;
                switch(x) {
                        case 10 :
                        case 9  :
                        case 8  : GPA = 4.0, grd = "A+"; break;
                        case 7  : GPA = 3.5, grd = "A"; break;
                        case 6  : GPA = 3.0, grd = "B"; break;
                        case 5  : GPA = 2.5, grd = "C"; break;
                        case 4  : GPA = 2.0, grd = "D"; break;
                        default : GPA = 0.0, grd = "F"; break;
                }
        }
} course[MX+3];

void takeInput( int n_o_crs ) {
        for(int i=1; i<=n_o_crs; i++) {
                cout << "Marks in Course " << i << " : ";
                cin >> course[i].mrks;
        }
}

void divdr() {
        cout << "  +";
        for(int i=1; i<=36; i++) {
                cout << "-";
                if( i%9 == 0 ) cout << "+";
        }
        cout << endl;
}

void prntTable( int n ) {
        cout << endl << "GRADE TABLE" << endl;
        divdr();
        cout << "  | Course  |" << "  Marks  |" << "   GP    |" << "  Grade  |" << endl;
        divdr();
        cout << fixed << setprecision(2);
        double sm = 0;
        bool flg = true;
        for(int i=1; i<=n; i++) {
                cout << "  | " << setw(4) << i  << "    |  " <<  setw(4) << course[i].mrks << "   |  " <<  setw(4) << course[i].GPA << "   |  " <<  setw(4) << course[i].grd  << "   |" << endl;
                divdr();
                if( course[i].GPA == 0 ) flg = false;
                sm += course[i].GPA;
        }
        if( !flg ) sm = 0;
        cout << endl << "\tTotal GPA : " << sm/(double)n << endl;
}

int main() {
        int n_o_crs;
        while( true ) {
                cout << endl << "Enter the number of courses : ";
                cin >> n_o_crs;
                takeInput( n_o_crs );

                for(int i=1; i<=n_o_crs; i++) {
                        course[i].grdFinder();
                }

                prntTable( n_o_crs );

                int choice;
                cout << endl << "If you want to continue press 1 else press 0 ? ";
                cin >> choice;
                if( choice != 1 ) break;
        }

        return 0;
}
