#include <iostream>
#include <algorithm>
#define size 5
using namespace std;

int blocks[size] = {200,100,300,400,500};

void firstfit(int process[], int n)
{
    int util_mem = 0 , internal_frag = 0, external_frag = 0;
    int last_allocated = 0;
    bool isallocated = false;
    for(int i = 0; i < n ;i++)
    {
        int start_index = last_allocated;
        isallocated = false;
        for(int j = start_index; j < size ; j++)
        {
            if(process[i] <= blocks[j])
            {
                cout << "Process " << i+1 << " is allocated to block " << j+1 << endl;
                util_mem += process[i];
                blocks[j] -= process[i];
                internal_frag += blocks[j];
                isallocated = true;
                last_allocated = j;
                break;
            }
        }
        if(!isallocated)
        {
            for(int j = 0 ; j < start_index ;j++)
            {
                if(process[i] <= blocks[j])
                {
                    cout << "Process " << i+1 << " is allocated to block " << j+1 << endl;
                    util_mem += process[i];
                    blocks[j] -= process[i];
                    internal_frag += blocks[j];
                    isallocated = true;
                    last_allocated = j;
                    break;
                }
            }
        }

        if(!isallocated)
            cout << "Process " << i + 1 << " is not allocated" << endl;
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

    firstfit(process, n);
}