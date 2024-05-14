#include <iostream>
#include <vector>

using namespace std;
int main() {
    int n = 5;
    vector<int> forks(n, 1); // 1 represents the fork is available, 0 represents it's in use

    int philosopher;

    while(true) {
        cout << "Enter the philosopher who wants to eat (-1 to exit): ";
        cin >> philosopher;
        if(philosopher == -1) {
            break;
        }
        else {
            cout << "P" << philosopher << " is now thinking to eat" << endl;

            int left_fork = philosopher - 1;
            int right_fork = (philosopher) % n;

            if(forks[left_fork] && forks[right_fork]) {
                forks[left_fork] = 0;
                forks[right_fork] = 0;

                cout << "P" << philosopher << " has acquired forks " << left_fork + 1 << " and " << right_fork + 1 << endl;
                cout << "P" << philosopher << " starts eating..." << endl;
                cout << "P" << philosopher << " stops eating" << endl;

                forks[left_fork] = 1;
                forks[right_fork] = 1;
            } else {
                cout << "P" << philosopher << " cannot eat now. Forks are not available." << endl;
            }
        }
    }
    return 0;
}
