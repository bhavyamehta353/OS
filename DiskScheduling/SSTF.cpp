#include <iostream>
using namespace std;
void SSTF(int arr[] , int n)
{
    int head;
    int visited[n];
    int tracks = 0;
    int sum = 0;
    cout << "Enter head:";;
    cin >> head;
    for(int i = 0 ; i < n; i++)
    {
        visited[i] = 0;
    }
    while(tracks != n)
    {
        int distance;
        int min = INT_MAX;
        int min_index = -1;
        for(int i = 0; i < n ; i++)
        {
            distance = abs(arr[i] - head);
            if(distance < min && !visited[i])
            {
                min = distance;
                min_index = i;
            }
        }
        sum += min;
        visited[min_index] = 1;
        head = arr[min_index];
        tracks++;
    }
    cout << endl << "Total Seek Operations:" << sum << endl;
}
int main()
{
    int n;
    cout << "Enter seq size:";
    cin >> n;
    int seq[n];
    for(int i = 0 ; i < n ; i++)
        cin >> seq[i];
    SSTF(seq, n);
}