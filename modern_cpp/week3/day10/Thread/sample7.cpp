/*
    create an array of 3 threads
        1 - should calaulate square fo each number in the array and store in a result assay(position 1-5)
        2 - should calculate cube of each nhumber in the array and store in a result array(position 6 - 10)
        3 - should calculate factorial of each number in the array and store in a result array(position 11 - 15)

    number in input array between (1-10)
*/

#include<thread>
#include<iostream>
#include<array>



int main() {
    std::array<int, 15> result{5};
    int number = 5;
    std::array<std::thread, 3> arr{
            std::thread(
                [&](int number = 10) { for(int i = 0; i < 5; i++) {
                        result [i] = number * number;      
                    } }
            ),
            std::thread(
                [&](int number = 10) { for(int i = 5; i < 10; i++) {
                        result [i] = number * number * number;      
                    } }
            ),
            std::thread(
                [&](int number = 10) { for(int i = 10; i < 15; i++) {
                        result [i] = number + 10;      
                    } }
            )
    };

    for(std::thread& t : arr) {
        if(t.joinable()) {
            t.join();
        }
    }

    for(int i = 0; i < 15; i++) {
        std::cout<<result[i]<<"\n";
    }
}