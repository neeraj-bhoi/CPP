/*
    objective : Design an adapter to acceept
        a vector of integers
        a predicate(a function that returns true/false based on a single input)

        use the predicate to print data from the vector

        predicate:(a function that takes one argument and returns true/false)
*/

// std::vector<int> {10, 12, 13, 15, 14};

/*
    divisible by 
        2(even) : 10, 12, 14
        3 : 12, 15
        7 : 14
        6 : 12
        5 : 10, 15
    primes : 13
*/
#include<functional>
#include<iostream>
#include<vector>
#include<math.h>

bool checkprime(int n) {
    // Check if n=1 or n=0
    n = abs(n);
    if (n <= 1)
        return false;
    // Check if n=2 or n=3
    if (n == 2 || n == 3)
        return true;
    // Check whether n is divisible by 2 or 3
    if (n % 2 == 0 || n % 3 == 0)
        return false;
     
    // Check from 5 to square root of n
    // Iterate i by (i+6)
    for (int i = 5; i <= sqrt(n); i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
 
    return true;
}

void Adapter(std::function<bool(int)> predicate, const std::vector<int>& data) {
    for(int val : data) {
        if(predicate(val)) { std::cout<<val<<"\n"; }
    }
}

int main() {
    Adapter(
        [](int number) {return number % 5 == 0;},
        std::vector<int> {10, 20, 46, 30, 26}
    );

    Adapter(
        [](int number) {return number % 5 == 0 && number % 3 == 0;},
        std::vector<int> {10, 20, 46, 30, 26}
    );

    Adapter(
        [](int number) {return checkprime(number);},
        std::vector<int> {10, 20, 7, 46, 30, 26}
    );
}