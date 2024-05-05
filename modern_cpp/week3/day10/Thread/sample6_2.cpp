/*
    singleton sample5
*/
#include<iostream>
#include<thread>
#include<mutex>
#include<array>
#include<memory>

/*
    one object of this class will be responsible for one connection mechanism to the bank
*/

class BankingOperations;

using operationPointer = std::shared_ptr<BankingOperations>;

class BankingOperations
{
private:
    int _amount{0};
    std::mutex mt;
    static operationPointer _solo_hero_obj;
    BankingOperations(int amount) : _amount{amount} {}

public:
    BankingOperations() = delete;
    BankingOperations(const BankingOperations&) = delete;
    BankingOperations& operator=(const BankingOperations&) = delete;
    BankingOperations(BankingOperations&&) = delete;
    BankingOperations& operator=(BankingOperations&&) = delete;
    ~BankingOperations() = default;

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

    static operationPointer getFirstInstance(int amount) {
        if(_solo_hero_obj) {
            return _solo_hero_obj;
        } else {
            // _solo_hero_obj = new BankingOperations(amount);
            _solo_hero_obj.reset(new BankingOperations(amount));
            return _solo_hero_obj;
        }
    }

    int amount() const { return _amount; }
    void setAmount(int amount) { _amount = amount; }
};

operationPointer BankingOperations::_solo_hero_obj {nullptr};


int main() {
    operationPointer obj = BankingOperations::getFirstInstance(1000);

    std::array<std::thread, 2> arr = {
        std::thread(&BankingOperations::Withdraw, obj),
        std::thread(&BankingOperations::Deposit, obj)
    };

    for(std::thread& t : arr) {
        //good practice
        if(t.joinable()) {  //if true then joinable.... still wait(check if can be joined)
            t.join();
        }
    }

    std::cout<<"Final amount id : " << obj->amount() << "\n";
}