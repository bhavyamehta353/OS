    #include <iostream>
    using namespace std;
    int n1,n2;
    void FIFO(int frames[] , int pages[])
    {
        int hits = 0, miss = 0;
        int k = 0;
        for(int i = 0; i < n1 ; i++)
            frames[i] = -1;

        for(int i = 0 ; i < n2 ; i++)
        {
            bool found = false; 
            for(int j = 0 ; j < n1; j++ )
            {
                if(frames[j] == pages[i]) //find if an existing page in frame matches the
                {                         // current page
                    hits++;
                    found = true;
                    break;
                }
            }
            if(found == false)
            {
                frames[k] = pages[i];
                miss++;
                k = (k+1)%n1; //circular fashion for FIFO
            }
            for(int x = 0 ; x < n1; x++)
                cout << frames[x] << " ";
            cout << endl;

            cout << "Hits:" << hits << endl;
            cout << "Miss:" << miss << endl;
            cout << endl;
        }
    }

    int main()
    {
        cout << "Enter the number of frames:";
        cin >> n1;
        cout << "Enter the number of pages:";
        cin >> n2;
        int frames[n1];
        int pages[n2];
        for(int i = 0; i < n2; i++)
            cin >> pages[i];
        FIFO(frames, pages);
        return 0;
    }