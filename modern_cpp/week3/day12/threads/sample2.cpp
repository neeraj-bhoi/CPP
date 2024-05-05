#include<future>    //async threading
#include<iostream>


void Factorial(/*int number*/ std::future<int>& ft) {
    int* ptr = (int*)malloc(4);     //line can be executed before int

    //wait for event
    int n = ft.get();       //this thread will now get blocked till input comes..

    int result = 1;
    for(int i = 2; i <= n; i++) {
        result *= i;
    }
    *ptr = result;
    std::cout<<"final answer is : "<<*ptr;
}

int main() {
    //make a promise : compiler, i will give you an integer in future
    std::promise<int> pr;
    std::future<int> ft = pr.get_future();

    //producer will work on promise, and consumer on future
    //promise is used for setting the value, and future is used for reading the value.

    std::future<void> result = std::async(Factorial, std::ref(ft));
    // in this call result is accesing value passed by Factorial -->
    // so Factorial becomes producer, and main becomes consumer

    int value = 0;
    std::cin>>value;
    // promise fulfill
    
    pr.set_value(value);    //notify


    //what if main wants to do something after factorial
    result.get();
    std::cout<<"goodbye\n";
}