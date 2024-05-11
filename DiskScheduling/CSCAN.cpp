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
    if(dir == 0) // towards larger values
    {
        sum = (max_track - head) + (max_track - min_track);
        int curr_head = min_track;
        int index = -1;
        for(int i = 0 ; seq[i] < head; i++)
        {
            index = i;
        }
        sum += (seq[index] - curr_head);
        cout << "Totak Seek Operations: " << sum << endl;
    } 
    else
    {
        sum = (head - min_track) + (max_track - min_track);
        int curr_head = max_track;
        int index = - 1;
        for(int i = size - 1; seq[i] > head; i--)
        {
            index = i;
        }
        sum += (curr_head - seq[index]);
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