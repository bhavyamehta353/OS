#include <iostream>
#include <limits.h>
using namespace std;
# define size 3
# define n 10
int frames[size] = {-1};
int pages[n] = {4, 7, 6, 1, 7, 6, 1, 2, 7, 2};
void Optimal()
{
    int hits = 0, miss = 0;
    int pageindex[size];
    fill_n(pageindex, size, -1);

    for (int i = 0; i < n; i++)
    {
        bool found = false;
        for (int j = 0; j < size; j++)
        {
            if (frames[j] == pages[i])
            {
                hits++;
                found = true;
                pageindex[j] = i;
                break;
            }
        }

        if (!found)
        {
            miss++;
            int maxIndex = 0;
            int maxDistance = -1;
            for (int j = 0; j < size; j++)
            {
                if (pageindex[j] == -1)
                {
                    maxIndex = j;
                    break;
                }
            }
            if (maxIndex == size)
            {
                for (int j = 0; j < size; j++)
                {
                    int farthest = -1;
                    for (int k = i + 1; k < n; k++)
                    {
                        if (pages[k] == frames[j])
                        {
                            if (k > farthest)
                            {
                                farthest = k;
                                maxIndex = j;
                            }
                            break;
                        }
                    }
                    if (farthest == -1)
                    {
                        maxIndex = j;
                        break;
                    }
                }
            }

            frames[maxIndex] = pages[i];
            pageindex[maxIndex] = i;
        }

        cout << "Frames after reference " << i + 1 << ": ";
        for (int x = 0; x < size; x++)
        {
            cout << frames[x] << " ";
        }
        cout << endl;
    }

    cout << "Number of Hits: " << hits << endl;
    cout << "Number of Misses: " << miss << endl;
    cout << "Hit Ratio: " << (float)hits / (float)n << endl;
    cout << "Miss Ratio: " << (float)miss / (float)n << endl;
}

int main()
{
    fill_n(frames, size, -1);
    Optimal();
    return 0;
}
