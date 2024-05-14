#include <iostream>
#include <algorithm>
using namespace std;

struct Process{
    int pid, at, bt , ct , priority;
};
bool compareAT(Process a, Process b)
{
    return a.at < b.at;
}
void Priority(struct Process P[], int n)
{
   int time = 0;
   int completed = 0;
   int visited[n];
   fill(visited, visited + n , 0);
   while(completed != n)
   {
        int maxP = INT_MIN;
        int maxP_index = -1;

        for(int i = 0 ; i < n ; i++)
        {
            if(P[i].at <= time && !visited[i] && P[i].priority > maxP) //highest priority and its index arrived and not already visited
            {
                maxP = P[i].priority;
                maxP_index = i;
            }
        }
        if(maxP_index == -1)   // if no process is available then move time to the arrival time of next process
        {
            time++;
            continue;
        }
        visited[maxP_index] = 1;
        P[maxP_index].ct = time + P[maxP_index].bt; // Non preemptive so adding BT
        time += P[maxP_index].bt;
        completed++;
   }
   for(int i = 0 ; i < n ; i++)
    cout << P[i].ct << " ";
    int TT[n] , WT[n];
    float ATT = 0.0 , AWT = 0.0;
    for(int i = 0; i < n; i++)
    {
        TT[i] = P[i].ct - P[i].at;
        WT[i] = TT[i] - P[i].bt;
        ATT += TT[i];
        AWT += WT[i];
    }
    cout << endl;
    cout << "AWT : "<< AWT / n << endl;
    cout << "ATT : "<< ATT / n << endl;
}
int main()
{
    int size; 
    cout << "Enter number of processes:";
    cin >> size;
    struct Process P[size];
    for(int i = 0; i < size; i++)
    {
        P[i].pid = i + 1;
        cout << "Enter Priority, AT, BT of Process" << i + 1 << ":";
        cin >> P[i].priority >> P[i].at >> P[i].bt;
    }

    sort(P , P + size , compareAT);
    Priority(P, size);
}
