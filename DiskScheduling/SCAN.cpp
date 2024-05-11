#include <iostream>
using namespace std;
void SCAN(int seq[], int size , int dir)
{
    int head;
    cout << "Enter head:";
    cin >> head;
    int min_track = 0;
    int max_track;
    cout << endl << "Enter max track:";
    cin >> max_track;

    sort(seq, seq + size);
    int sum = 0;
    if(dir == 0)
    {
        sum = (max_track - head) + (max_track - seq[0]);
        cout << "Totak Seek Operations: " << sum << endl;
    }    
    else
    {
        sum = (head - min_track) + (seq[size - 1] - min_track);
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