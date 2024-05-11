#include <iostream>
#include <algorithm>
using namespace std;
struct Process{
    int at, bt, ct, pid;
};
bool compareAT(Process a, Process b)
{
    return a.at < b.at;
}

bool compareBT(Process a, Process b)
{
    return a.bt < b.bt;
}
void SJF(struct Process P[] , int n)
{            
    sort(P + 1, P + n, compareBT);
    for(int i = 0 ; i < n ;i++)
    {
        if(i == 0)
            P[i].ct = P[i].at + P[i].bt;
        else
            P[i].ct = P[i-1].ct + P[i].bt;
    }
    cout << endl << "Gantt Chart" << endl << "0" << " ";
    for(int i = 0 ; i < n ; i++)
        cout << P[i].ct << " ";
    
    int TT[n] , WT[n];
    for(int i = 0 ; i < n ; i++)
    {
        TT[i] = P[i].ct - P[i].at;
        WT[i] = TT[i] - P[i].bt;
    }

    float AWT = 0.0 , ATT = 0.0; 
    for(int i = 0 ; i < n ; i++)
    {
        AWT += WT[i];
        ATT += TT[i];
    }
    cout << endl; 
    cout << "ATT = " << ATT/n << endl;
    cout << "AWT = " << AWT/n << endl;
}
int main()
{
    int size;
    cout << "Enter the number of processes: ";
    cin >> size;
    struct Process P[size];
    for(int i = 0; i < size; i++)
    {
        P[i].pid = i + 1;
        cout << "Enter the arrival time and burst time of process " << i+1 << ": ";
        cin >> P[i].at >> P[i].bt;
    }
    sort(P, P+size , compareAT);
    SJF(P, size);
}