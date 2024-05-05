/*
    problems with sample1.cpp

    both Square() and Cube should have run parallely....
    (hardware efficiency) { use of different cores }
*/

#include<iostream>
#include<array>
#include<thread>
#include<mutex>

std::mutex mt;  //mutex is a binary semaphore

void Square(std::array<int, 5>& data) {
    for(int number : data) {
        std::this_thread::sleep_for(std::chrono::seconds(1));   //1 second artificial delay
        mt.lock();
        std::cout<<"square of number : "<<number <<" is : "<<number * number<<"\n";
        mt.unlock();
    }
}

void Cube(std::array<int, 5>& data) {
    for(int number : data) {
        std::this_thread::sleep_for(std::chrono::seconds(1));   //1 second artificial delay

        //only 1 executing entity should be doing this at a time.[CRITICAL SECTION]
        mt.lock();
        std::cout<<"Cube of number : "<<number <<" is : "<<number * number * number<<"\n";
        mt.unlock();
    }
}

int main() {
        // main thread starts, creates an array object in local stack memory
    std::array<int, 5> data {1, 2, 3, 4, 5};
    
        //we launhch a new thread
            /*
                A thread is a mini program. As a developer, t1 object is a "handle" for me to interact with 
                the thread in some way. This t1 is attached to Square mini program We have also passed "data"
                by reference which is required by the Square Function.
            */
    std::thread t1(&Square, std::ref(data));
        //we launhch a new thread
    std::thread t2(&Cube, std::ref(data));
/*
    COUT BUFFER is a shared memory responsible for printing, which might be unsynchronised...
    jo bhi uotput karna hai wo COUT BUFFER me jata hai, t1 and t2 will fight for both..
*/

            /*
                once you make a thread you are starting a new mini program.
                now you technically loose control over it..
                (sequences might change of all the threads(Square, Cube, Main) present)
            */

    //Signal as a result/summary/satisfaction
    //join : wait for a thread. (one of the option for above task)
    t1.join();  //main will not proceed to next line until t1 finishes.
    t2.join();  //main will not proceed to next line until t2 finishes.

    std::cout<<"Goodbye\n";
}