#include <iostream>
#include <algorithm>
using namespace std;
int allocation[5][3] = {
    {0, 1, 0},
    {2, 0, 0},
    {3, 0, 2},
    {2, 1, 1},
    {0, 0, 2},
};
int maxi[5][3] = {
    {7, 5, 3},
    {3, 2, 2},
    {9, 0, 2},
    {2, 2, 2},
    {4, 3, 3},
};
int available[3] = {3,3,2};
int need[5][3];
int sequence[5];
void Bankers()
{
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 3; j++)
            need[i][j] = maxi[i][j] - allocation[i][j];
    }
    cout << "Need:" << endl;
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 3; j++)
            cout << need[i][j] << " ";
        cout << endl;
    }
    int count = 0;
    int visited[5] = {0};
    while(count != 5)
    {
        bool canExecute = false;
        for(int i = 0; i < 5 ; i++)
        {
            if(!visited[i])
            {
                bool isSafe = true;
                for(int j = 0 ; j < 3; j++)
                {
                    if(need[i][j] > available[j])
                    {
                        isSafe = false;
                        break;
                    }
                }
                if(isSafe)
                {
                    canExecute = true;
                    visited[i] = 1;
                    sequence[count] = i;
                    count++; 
                    for(int j = 0 ; j < 3 ; j++)
                        available[j] += allocation[i][j];
                    break;
                }
            }
        }
        if(!canExecute)
        {
            cout << "System is in unsafe state" << endl;
            break;
        }
    }
    cout << "System is in safe state" << endl;
    for(int i = 0 ; i < 5 ; i++)
        cout << sequence[i] << " ";
    cout << endl;
}
int main()
{
    Bankers();
    return 0;
}