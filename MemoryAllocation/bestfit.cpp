#include <iostream>
#include <algorithm>
#define size 5
using namespace std;

int blocks[size] = {100,500,200,300,600};

void bestfit(int process[], int n)
{
    int util_mem = 0 , internal_frag = 0, external_frag = 0;
    for(int i = 0; i < n ;i++)
    {
        int min = INT_MAX;
        int min_index = -1;
        for(int j = 0; j < size ; j++)
        {
            if(process[i] <= blocks[j] && blocks[j] - process[i] < min)
            {
                min = blocks[j] - process[i];
                min_index = j;                
            }
        }
        if(min_index == -1)
            cout << "Process " << i + 1  << " cannot be allocated" << endl;
        cout << "Process " << i + 1 << "allocated to block" << min_index + 1 << endl;
        util_mem += process[i];
        internal_frag += min;
        blocks[min_index] = blocks[min_index] - process[i];
    }
    for(int i = 0; i < size; i++)
        external_frag += blocks[i];

    cout << "Total utilized memory is " << util_mem << endl;
    cout << "Total internal fragmentation is " << internal_frag << endl;
    cout << "Total external fragmentation is " << external_frag << endl;
}
int main()
{
    int n;
    cout << "Enter number of processes";
    cin >> n;
    int process[n];
    for(int i = 0; i < n; i++)
    {
        cin >> process[i];
    }

    bestfit(process, n);
}