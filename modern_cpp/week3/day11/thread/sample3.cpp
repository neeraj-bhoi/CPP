/*
    Producer consumer problem!

    2 workers in your program
        one of them may produce something 
        other will consume it (process the produced item)
*/

/*
    2 threads (2 workers)
        -main thread : take input and make value available.
        -1st once a signal is received from main to indicate " input received " , calcilate square

    why t1 should start before receiving input
        a) programmer calculates how many workers are required and triggers them
            at a time [thread pooling]
        b) t1 may want to do some other work even before data input is received
*/

#include<iostream>
#include<thread>
#include<condition_variable>    //this is a semaphore
// #include<mutex>

int value = 0;
bool flag = false;
std::mutex mt;
std::condition_variable cv;


void operation() {
    int *ans = (int*) malloc(4);

    //wait for signal
    std::unique_lock<std::mutex> ul(mt);
    cv.wait(ul, [&]() { return flag; }); 

    *ans = value * value;
    std::cout<<"Square of " << value << " is : " << *ans;
    free(ans);
}

void takeInput() {
    std::lock_guard<std::mutex> lg(mt);
    std::cin>> value;
    flag = true;
    cv.notify_one();
}

int main() {
    std::thread t1(&takeInput);
    std::thread t2(&operation);

    t1.join();
    t2.join();
}