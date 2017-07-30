/*
        OOP Lab 3 Task 1
        C++ program to show the working duration of 5 employees of a company
        using structures, nested structures, structure methods,
        passing structures as parameters and structures as function return type
*/
#include <iostream>
#include <iomanip>
using namespace std;

struct time_data {
        int hur, mnt;
};

time_data update( time_data a ) {
        if( a.hur >= 24 ) a.hur -= 24;
        if( a.mnt >= 60 ) a.mnt -= 60;
        return a;
}
void time_formet( time_data a ) {
        a = update( a );
        if( a.hur < 10 ) cout << "0" << a.hur;
        else cout << a.hur;
        cout << ":";
        if( a.mnt < 10 ) cout << "0" << a.mnt;
        else cout << a.mnt;
}

void durationPrint( time_data a ) {
        cout << "\t" << setw(2) << a.hur;
        if( a.hur > 1 ) cout << " hours ";
        else cout << " hour  ";
        cout << setw(2) << a.mnt;
        if( a.mnt > 1 ) cout << " minutes";
        else cout << " minute";
        cout << endl;
}

struct employe_data {
        int id_no;
        time_data entrnc_time, levng_time, drsn;
        /// methods
        void inputData() {
                cout << "ID No : ";
                cin >> id_no;
                cout << "Entrance Time (HH MM) : ";
                cin >> entrnc_time.hur >> entrnc_time.mnt;
                cout << "Leaving Time  (HH MM) : ";
                cin >> levng_time.hur >> levng_time.mnt;
        }

        void clcultDurssn() {
                if( entrnc_time.mnt > levng_time.mnt ) entrnc_time.hur++, levng_time.mnt += 60;
                drsn.mnt = levng_time.mnt - entrnc_time.mnt;
                if( levng_time.hur < entrnc_time.hur ) levng_time.hur += 24;
                drsn.hur = levng_time.hur - entrnc_time.hur;
        }

        void printData() {
                cout << setw(4) << "ID : " << id_no << "\t" << "Start : ";
                time_formet( entrnc_time );
                cout << "\t" << "End : ";
                time_formet( levng_time );
                durationPrint( drsn );
        }

};

int main() {
        employe_data rcrd[10];
        for(int i=0; i<5; i++) {
                rcrd[i].inputData();
        }

        cout << endl << "Daily office duration record of the employees :" << endl;
        for(int i=0; i<5; i++) {
                rcrd[i].clcultDurssn();
                rcrd[i].printData();
        }

        return 0;
}
