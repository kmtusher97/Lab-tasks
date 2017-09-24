#include <iostream>
#include <iomanip>
using namespace std;
///////////////////////////////////////////////////////////////
class bowler;
class batsman;
class player;
///////////////////////////////////////////////////////////////
class batsman
{
    private:
        string name;
        int run, matches;
        const int plyr_typ = 1;
    public:
        void get_batsman_data()
        {
            cout << "Name: ", cin >> name;
            cout << "Total Runs: ", cin >> run;
            cout << "Matches: ", cin >> matches;
        }
        void show_batsman_data()
        {
            cout << "Player Type: Batsman" << endl;
            cout << "Name: " << name << endl;
            cout << "Total Runs: " << run << endl;
            cout << "Matches: " << matches << endl;
            cout << "Average: " << fixed << setprecision(3) << run/(matches*1.0) << endl;
        }
        friend player get_data( batsman, bowler );
};
////////////////////////////////////////////////////////////////
class bowler
{
    private:
        string name;
        int run, wickets, matches;
        const int plyr_typ = 2;
    public:
        void get_bowler_data()
        {
            cout << "Name: ", cin >> name;
            cout << "Total Wickets: ", cin >> wickets;
            cout << "Total Runs: ", cin >> run;
            cout << "Matches: ", cin >> matches;
        }
        void show_bowler_data()
        {
            cout << "Player Type: Bowler" << endl;
            cout << "Name: " << name << endl;
            cout << "Total Wickets: " << wickets << endl;
            cout << "Total Runs: " << run << endl;
            cout << "Matches: " << matches << endl;
            cout << "Wicket Average: " << fixed << setprecision(3) << wickets/(matches*1.0) << endl;
            cout << "Run Average: " << fixed << setprecision(3) << run/(matches*1.0) << endl;
        }
        friend player get_data( batsman, bowler );
};
////////////////////////////////////////////////////////////////
class player {
    public:
        batsman b1;
        bowler b2;
};
///////////////////////////////////////////////////////////////
player get_data( batsman a, bowler b ) {
    a.get_batsman_data();
    b.get_bowler_data();
    cout << endl;
    return {a, b};
}
////////////////////////////////////////////////////////////////
int main()
{
    batsman btsmn[2];
    bowler bwlr[2];

    player ply1 = get_data(btsmn[0], bwlr[0]);
    ply1.b1.show_batsman_data();
    cout << endl;
    ply1.b2.show_bowler_data();

    return 0;
}
