/*
    withdraw: withrdrew takes 10 units of money from amount
    Deposit: adds 10 units of money to amount

    RUN withdraw and Deposit bith 100 times each on initial amount of 1000

    what will be final amount after 200 transactions are completed?  :: 1000
*/

#include<iostream>
#include<thread>
#include<mutex>

int amount = 1000;
std::mutex mt;

void Withdraw() {
    for(int i = 0; i < 100; i++) {
        std::this_thread::sleep_for(std::chrono::microseconds(1));
        mt.lock();
        amount -= 10;   //critical section
        mt.unlock();
    }
}

void Deposit() {
    for(int i = 0; i < 100; i++) {
        std::this_thread::sleep_for(std::chrono::microseconds(1));
        mt.lock();
        amount += 10;   //critical section
        mt.unlock();
    }
}

int main() {
    std::thread t1(&Withdraw);
    std::thread t2(&Deposit);

    t1.join();
    t2.join();

    std::cout<<"final amount : "<<amount<<"\n";
}
