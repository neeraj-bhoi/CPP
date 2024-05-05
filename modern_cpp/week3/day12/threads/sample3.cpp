/*
    objective : 
        Design a consumer for :
            - make allocations on heap for 10 integers.
            - save square of first 10 integers on the heap storage created.
            - calculating sum of first N natural numbers, where N is accepted assynchronously in the function and return the value

        producer thread for : 
            - Launching a consumer Accepting N and passing to consumer
*/

#include<future>
#include<iostream>

void Consumer(std::future<int>& ft) {
    int* ptr = (int*) malloc(40);

    auto f1 = [](int number) { return number * number; };
    for(int i = 1; i <=10; i++) {
        ptr[i-1] = f1(i);
    }
    for(int i = 1; i <10; i++) {
        std::cout<<ptr[i-1]<<"\n";
    }

    int n = ft.get();   // one future value can only use .get() once
    // int sum = 0;
    // for(int i = 1; i <=n; i++) {
    //     sum += i;
    // }
    free (ptr);
    // return (n*(n+1)/2);
}


int main() {
    std::promise<int> pr;
    std::future<int> ft = pr.get_future();

    std::future<void>  result = std::async(&Consumer, std::ref(ft));

    int value{0};
    std::cin>>value;
    pr.set_value(value);

    // std::cout<<"the answer is : "<<result.get();    //wait for result to come, and receive it.
    result.wait();
}