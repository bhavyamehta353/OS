#include <iostream>
using namespace std;
void SCAN(int seq[], int size , int dir)
{
    int head;
    cout << "Enter head:";
    cin >> head;
    sort(seq, seq + size);
    int sum = 0;
    if(dir == 0)
    {
        sum = (seq[size - 1]  -  head) + (seq[size - 1] - seq[0]);
        int curr_head = seq[0];
        int index = -1;
        
        for(int i = 0 ; seq[i] < head; i++)
            index = i;
        
        sum += seq[index] - curr_head;
        cout << "Totak Seek Operations: " << sum << endl;
    }    
    else
    {
        sum = (head - seq[0]) + (seq[size - 1] - seq[0]);
        int curr_head = seq[size - 1];
        int index = -1;
        for(int i = size - 1 ; seq[i] > head ; i--)
            index = i;

        sum += curr_head - seq[index];
        cout << "Totak Seek Operations: " << sum << endl;
    }
}

int main()
{
    int size;
    cout << "Enter number of tracks:";
    cin >> size;
    int seq[size];
    for(int i = 0; i < size; i++)
        cin >> seq[i];
    int dir;
    cout << "Enter direction 0 for down and 1 for up:";
    cin >> dir;
    SCAN(seq, size , dir);
}