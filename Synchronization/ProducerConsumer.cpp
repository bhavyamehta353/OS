#include <iostream>
#include <thread>
#include <unistd.h>
using namespace std;

const int BUFFER_SIZE = 10; // Adjustable buffer size
int buffer[BUFFER_SIZE];
int in = 0, out = 0; // Indexes for producer and consumer
int semaphore = BUFFER_SIZE; // Semaphore (initially equal to buffer size)
int producer() {
    if(semaphore == 0) {
       cout << "Buffer full" << endl;
       return -1;
    }
    // Critical section (adding to buffer)
    int item = rand() % 100;
    buffer[in] = item;
    in = (in + 1) % BUFFER_SIZE;

    semaphore--; // Decrement semaphore after successful addition
    cout << "Produced: " << item << endl;
    return item;
}
int consumer() {
    if(semaphore == BUFFER_SIZE) {
        cout << "Buffer empty" << endl;
        return -1;
    }
    // Critical section (removing from buffer)
    int item = buffer[out];
    out = (out + 1) % BUFFER_SIZE;
    semaphore++; // Increment semaphore after successful removal
    cout << "Consumed: " << item << endl;
    return item;
}
int main() {
    int choice, item;
    while (true) {
        // Generate random choice between producing and consuming
        choice = rand()%2 + 1;
        switch (choice) {
            case 1:
                producer();
                break;
            case 2:
                item = consumer();
                break;
        }
        sleep(2);
    }
    return 0;
}
