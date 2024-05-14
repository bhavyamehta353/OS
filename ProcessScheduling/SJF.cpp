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
bool compareCT(Process a, Process b)
{
    return a.ct < b.ct;
}
void SJF(struct Process P[] , int n)
{            
    int time = 0;
    int completed = 0;
    int visited[n];
    fill(visited ,visited + n , 0);
    while(completed < n)
    {
        int min_index = -1; //for min burst time
        int min = INT_MAX;
        for(int i = 0 ; i < n ; i++)
        {
            if(P[i].at <= time && !visited[i] && P[i].bt < min) // finds the index of min burst time among processes that have arrived
            {
                min = P[i].bt;
                min_index = i;
            }
        }
        if(min_index == -1) //if no processes have arrived
        {
            time++;
            continue;
        }
        // else
        visited[min_index] = 1; 
        P[min_index].ct = time + P[min_index].bt; // since it is non preemptive
        time += P[min_index].bt;
        completed++;
    }
    sort(P, P + n , compareCT);
    cout << endl << "Gantt Chart" << endl << "0" << " ";
    for(int i = 0 ; i < n ; i++)
        cout << P[i].ct << " ";
    
    int TT[n] , WT[n];
    float AWT = 0.0 , ATT = 0.0; 
    for(int i = 0 ; i < n ; i++)
    {
        TT[i] = P[i].ct - P[i].at;
        WT[i] = TT[i] - P[i].bt;
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
