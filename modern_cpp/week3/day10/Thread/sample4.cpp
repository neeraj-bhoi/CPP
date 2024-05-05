#include<iostream>
#include<thread>
#include<mutex>

int amount = 1000;
std::mutex mt;

void Withdraw() {
    for(int i = 0; i < 100; i++) {
        std::this_thread::sleep_for(std::chrono::microseconds(1));
        
        // better way (instead of std::mutex way and mt.lock() , mt.unlock())
        std::lock_guard<std::mutex> lk(mt); //lock guard

        amount -= 10;   //critical section
    
    }
}

void Deposit() {
    for(int i = 0; i < 100; i++) {
        std::this_thread::sleep_for(std::chrono::microseconds(1));

        std::lock_guard<std::mutex> lk(mt); //lock guard  

        amount += 10;   //critical section
    }
}

int main() {
    std::thread t1(&Withdraw);
    std::thread t2(&Deposit);

    t1.join();
    t2.join();

    std::cout<<"final amount : "<<amount<<"\n";
}
