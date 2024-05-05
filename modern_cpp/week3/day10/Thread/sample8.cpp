/*
    better sample7.cpp
*/

#include<thread>
#include<iostream>
#include<array>
#include<functional>

using FnType = std::function<void(int)>;
using FnContainer = std::array<FnType, 3>;
using InputDataContainer = std::array<int, 5>;
using ResultContainer = std::array<int, 15>;
using ThreadArray = std::array<std::thread, 3>;

void StoreFunctionInContainer(FnContainer& fns, InputDataContainer& data, ResultContainer& result) {

    fns[0] = [&](int k) {
        for(int number : data) {
            result[k++] = number * number;
        }
    };

    fns[1] = [&](int k) {
        for(int number : data) {
            result[k++] = number * number * number;
        }
    };

    fns[2] = [&](int k) {
        for(int number : data) {
            if(number == 1) {
                result[k++] = 1;
            } else {
                int amount = 1;
                for(int i = 2; i <= number; i++) {
                    amount *= i;
                }
                result[k++] = amount;
            }
        }
    };
}

void MapFunctionToThread(FnContainer& fns, ThreadArray& thArr) {
    int pos[3] = {0, 5, 10};
    for(int i = 0; i < thArr.size(); i++) {
        thArr[i] = std::thread(fns[i], pos[i]);
    }
}

void joinThreads(ThreadArray& thArr) {
    for(std::thread& t : thArr) {
        if(t.joinable()) {
            t.join();
        }
    }
}

void Display(const ResultContainer& result) {
        for(const int val : result) {
        std::cout<<val<<"\n";
    }
}

int main() {

    std::array<int, 5> data{1, 2, 3, 4, 5};
    std::array<int,15> result;
    std::array<std::thread, 3> thArr;
    FnContainer fns;

    StoreFunctionInContainer(fns, data, result);

    MapFunctionToThread(fns, thArr);

    joinThreads(thArr);

    Display(result);


}