#include <iostream>
#include <algorithm>
using namespace std;
# define size 3
# define n 10
int frames[size] = {-1};
int pages[n] = {4, 7, 6, 1, 7, 6, 1, 2, 7, 2};
void LRU()
{
    int hits = 0, miss = 0 , k = 0;
    int pageOrder[size]; // mantains index of pages added in the frame
    fill_n(pageOrder, size, -1);
    for(int i = 0 ; i < n ; i++)
    {
        bool found = false;
        for(int j = 0 ; j < size ; j++)
        {
            if(frames[j] == pages[i])
            {
                hits++;
                found = true;
                pageOrder[j] = i;
                break;
            }
        }
        if(!found)
        {
            miss++;
            while(k < size) // filling the first n frames
            {
                frames[k] = pages[i];
                pageOrder[k] = i;
                k++;
                break;
            }   
            if(miss > size)
            {
                int min_index = 0;
                int min = pageOrder[0];
                for(int l = 1; l < size; l++)
                {
                    if(pageOrder[l] < min) // find min index of page in PageOrder
                    {
                        min = pageOrder[l];
                        min_index = l;
                    }
                }
                frames[min_index] = pages[i]; 
                pageOrder[min_index] = i;
            }
        }
            for(int x = 0 ; x < size ; x++)
                cout << frames[x] << " ";
            cout << endl;
        }
    cout << "Number of Hits : " << hits << endl;
    cout << "Number of Misses : " << miss << endl;
    cout << "Hit Ratio : " << (float)hits/(float)n << endl;
    cout << "Miss Ratio : " << (float)miss/(float)n << endl;
    return;
}
int main()
{
    LRU();
    return 0;
}