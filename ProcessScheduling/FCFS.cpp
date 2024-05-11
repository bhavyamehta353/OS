#include <iostream>
#include <algorithm>
using namespace std;

struct Process
{
    int pid, at, bt ,ct; 
};
bool compareAT(Process a, Process b)
{
    return a.at < b.at;
}
void FCFS(struct Process P[], int size)
{
    int TT[size], WT[size];
    for(int i = 0 ; i < size ; i++)
    {
        if(i == 0)
            P[i].ct = P[i].bt;
        else
        {
            P[i].ct = P[i-1].ct + P[i].bt;
        } 
    }
    for(int i = 0 ; i < size ; i++)
    {
        TT[i] = P[i].ct - P[i].at;
        WT[i] = TT[i] - P[i].bt;
    }

    cout << endl;
    cout << "Gantt Chart" << endl;

    cout << "0" << " ";
    for(int i = 0 ; i < size ; i++)
    {    
        cout << P[i].ct << " ";
    }

    float ATT = 0.0, AWT = 0.0;
    for(int i = 0 ; i < size ; i++)
    {
        ATT += TT[i];
        AWT += WT[i];
    }

    cout << endl << "ATT: " << ATT/size << endl;
    cout << "AWT: " << AWT/size << endl;

}
int main()
{
    int size;
    cout << "Enter the number of processes: ";
    cin >> size;
    struct Process P[size];
    for(int i = 0 ; i < size ; i++)
    {
        P[i].pid = i + 1;
        cout << "Enter the arrival time and burst time of process " << i+1 << ": ";
        cin >> P[i].at >> P[i].bt;
    }

    sort(P , P+size , compareAT);
    for(int i = 0 ; i < size ; i++)
    {
        cout << P[i].pid << " " << P[i].at << " " << P[i].bt << endl;
    }
    
    FCFS(P, size);
    return 0;
}