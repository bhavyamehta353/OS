#include <iostream>
using namespace std;


void FCFS(int arr[], int n)
{
    int head;
    cout << "Enter head position:";
    cin >> head;
    int sum = 0;
    int current; 
    for(int i = 0 ; i < n ; i++)
    {
        current = arr[i];
        sum += abs(current - head);
        head = current;
    }
    cout << "Total Seek operations:" << sum << endl;
}
int main()
{
    int size;
    cout << "Enter sequence size:";
    cin >> size;
    int seq[size];
    for(int i = 0; i < size; i++)
        cin >> seq[i];
    FCFS(seq,size);

}