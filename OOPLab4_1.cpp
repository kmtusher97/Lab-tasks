/*
    OOP Lab 4
    * class
    * object
*/
#include <iostream>
using namespace std;

class time {
    private:
        int hour, minute;
    public:
        inline void get_time() {
            cin >> hour >> minute;
        }

        inline time calculate_duration( time tmp1, time tmp2 ) {
            time tmp3;
            if( tmp2.minute < tmp1.minute ) {
                tmp2.minute += 60;
                tmp1.hour++;
            }
            if( tmp2.hour < tmp1.hour ) {
                tmp2.hour += 24;
            }
            tmp3.minute = tmp2.minute - tmp1.minute;
            tmp3.hour = tmp2.hour - tmp1.hour;
            return tmp3;
        }

        inline void print_time() {
            if( hour < 10 ) {
                cout << "0";
            }
            cout << hour << ":";
            if( minute < 10 ) {
                cout << "0";
            }
            cout << minute;
        }
};

class employee {
    private:
        int id;
        time entrnc, exit, duration;
    public:
        inline void get_emp_data() {
            cin >> id;
            entrnc.get_time();
            exit.get_time();
        }

        inline void calculation() {
            duration = duration.calculate_duration( entrnc, exit );
        }

        inline void print_data() {
            cout << id << "\t";
            entrnc.print_time();
            cout << "\t\t";
            exit.print_time();
            cout << "\t\t";
            duration.print_time();
            cout << endl;
        }
};

class employee_working_period_record {
    private:
        employee rcrd[10];
    public:
        inline void get_data() {
            cout << "Enter the ID no, entrance time (HH:MM), exit time (HH:MM) of five employee:" << endl;
            for(int i=0; i<5; i++) {
                rcrd[i].get_emp_data();
                rcrd[i].calculation();
            }
        }

        inline void display_data() {
            cout << endl << "ID\tEntrance\tExit\t\tDuration" << endl;
            for(int i=0; i<5; i++) {
                rcrd[i].print_data();
            }
        }
};

int main() {
    employee_working_period_record RCRD;
    RCRD.get_data();
    RCRD.display_data();

    return 0;
}
