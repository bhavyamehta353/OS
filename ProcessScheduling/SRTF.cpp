#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

struct Process{
    int pid, at, bt, ct;
};
bool compareAT(Process a, Process b)
{
    return a.at < b.at;
}
void SJF(struct Process P[], int size)
{
    int rem_bt[size];

    for(int i = 0 ; i < size ;i++)
        rem_bt[i] = P[i].bt;
    
    int time = 0 ,complete = 0;
    
    while(complete != size)
    {
        int shortest = -1;
        int minm = INT_MAX;
        for(int i = 0 ; i < size ; i++)
        {
            if((P[i].at <= time) && rem_bt[i] > 0 && rem_bt[i] < minm)
            {
                minm = rem_bt[i];
                shortest = i;
            }
        }
            if(shortest == -1)
            {
                time++;
                continue;
            }
            rem_bt[shortest]--;
            if(rem_bt[shortest] == 0)
            {
                complete++;
                P[shortest].ct = time + 1;
            }
            time++;
    }
    int TT[size] , WT[size];
    float ATT = 0.0 , AWT = 0.0;
    for(int i = 0; i < size; i++)
    {
        TT[i] = P[i].ct - P[i].at;
        WT[i] = TT[i] - P[i].bt;
        ATT += TT[i];
        AWT += WT[i];
    }
    cout << "AWT : "<< AWT / size << endl;
    cout << "ATT : "<< ATT / size << endl;
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

    sort(P, P + size, compareAT);
    SJF(P,size);
}