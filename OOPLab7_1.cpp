#include <iostream>
#include <iomanip>
using namespace std;
////////////////////////////////////////////////////////////////
class player
{
    protected:
        string name;
        int jersey_no;
    public:
        void get_Player_data()
        {
            cout << "Name: "; cin >> name;
            cout << "Jersey No: ", cin >> jersey_no;
        }
        void show_player_data()
        {
            cout << "Player Name: " << name << endl;
            cout << "Jersey No: " << jersey_no << endl;
        }
        virtual void get_data() = 0;
        virtual void is_bowler_or_batsman() = 0;
};
////////////////////////////////////////////////////////////////
class batsman : public player
{
    private:
        int run, matches;
    public:
        void get_data()
        {
            player :: get_Player_data();
            cout << "Total Runs: ", cin >> run;
            cout << "Matches: ", cin >> matches;
        }
        void is_bowler_or_batsman()
        {
            cout << "Player Type: Batsman" << endl;
            player :: show_player_data();
            cout << "Total Runs: " << run << endl;
            cout << "Matches: " << matches << endl;
            cout << "Average: " << fixed << setprecision(3) << run/(matches*0.1) << endl;
        }
};
////////////////////////////////////////////////////////////////
class bowler : public player
{
    private:
        int wickets, matches;
    public:
        void get_data()
        {
            player :: get_Player_data();
            cout << "Total Wickets: ", cin >> wickets;
            cout << "Matches: ", cin >> matches;
        }
        void is_bowler_or_batsman()
        {
            cout << "Player Type: Bowler" << endl;
            player :: show_player_data();
            cout << "Total Wickets: " << wickets << endl;
            cout << "Matches: " << matches << endl;
            cout << "Average: " << fixed << setprecision(3) << wickets/(matches*0.1) << endl;
        }
};
////////////////////////////////////////////////////////////////
int main()
{
    player* plyr[12];
    int n = 0, choice;
    while( true )
    {
        cout << "Batsman / Bowler ? Enter (1/2): ";
        cin >> choice;
        if( choice == 1 )
        {
           plyr[n] = new batsman;
           plyr[n++] -> get_data();
        }
        else
        {
            plyr[n] = new bowler;
            plyr[n++] -> get_data();
        }

        cout << "\nContinue (1/0)? ";
        cin >> choice;
        if( choice == 0 ) break;
    }
    for(int i=0; i<n; i++)
    {
        cout << endl;
        plyr[i]->is_bowler_or_batsman();
    }
    return 0;
}
