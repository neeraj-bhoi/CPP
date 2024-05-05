/*
    RAII : 

*/
#include<iostream>
#include<thread>
#include<mutex>
#include<array>

/*
    one object of this class will be responsible for one connection mechanism to the bank
*/

class BankingOperations
{
private:
    int _amount{0};
    std::mutex mt;

public:
    BankingOperations() {}
    BankingOperations(const BankingOperations&) = delete;
    BankingOperations& operator=(const BankingOperations&) = delete;
    BankingOperations(BankingOperations&&) = delete;
    BankingOperations& operator=(BankingOperations&&) = delete;
    ~BankingOperations() {}
    BankingOperations(int amount) : _amount{amount}{}

    void Withdraw() {
        for(int i = 0; i < 100; i++) {
            std::this_thread::sleep_for(std::chrono::microseconds(1));
            std::lock_guard<std::mutex> lk(mt); 
            _amount -= 10;  
    
        }
    }

    void Deposit() {
        for(int i = 0; i < 100; i++) {
            std::this_thread::sleep_for(std::chrono::microseconds(1)); 
            std::lock_guard<std::mutex> lk(mt); 
            _amount += 10;   
        }
    }
};


int main() {
    BankingOperations b1{1000}; //value initialisation using {}

    std::array<std::thread, 2> arr = {
        std::thread(&BankingOperations::Withdraw, &b1),
        std::thread(&BankingOperations::Deposit, &b1)
    };

    for(std::thread& t : arr) {
        //good practice
        if(t.joinable()) {  //if true then joinable.... still wait(check if can be joined)
            t.join();
        }
    }
}