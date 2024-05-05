//  BIND

/*
problems in industry
    1) we cannot massively change the code after it is deployed for client
    2) Sometimes API paremeters need to be fixed- at a certain value
*/

#include<iostream>
#include<functional>
#include<cstring>
#include<list>

void Formula(const int x, const int y, const int z) {
    std::cout<<((x + y) - z);
}

//print nth value in list
void Magic(const std::list<int>& data, int n) {
    for(int val: data) {
        n--;
        if(n==0) {
            std::cout<<val<<"\n";
        }
    }
}


int main() {
    // strcpy();

    //connect(ip, port hostname, id, password)   //ip is 192.17.81.100, port is 22

    // Formula(10, 20, 30);

    //to fix one argument from user side...
    auto binded_formula = std::bind(&Formula, 100, std::placeholders::_1, std::placeholders::_2);
    binded_formula(30, 40, 50, 60);
    //placeholders for parameters to store.....

    auto binded_Magic = std::bind(&Magic, std::placeholders::_2, std::placeholders::_1);

    auto binded_strcpy = std::bind(&strcpy, std::placeholders::_2, std::placeholders::_1);

    // std::string msg;
    // binded_strcpy("harshit", msg);
    //                    |
    //            parameters swapped...

    auto fn = [](int number, int factor) { std::cout<< number * factor; };
    auto binded_lambda_fn = std::bind(fn, std::placeholders::_1, 40);
    //a lambda is an object. using & on a lambda means taking address of object. don't use & sign with lambda in bind.

    binded_lambda_fn(100);  //fn(100, 40);
    binded_lambda_fn(100, 20);    //fn(100, 40);
    binded_lambda_fn(100, 20, 30, 40);    //fn(100, 40);
}

/*
    void Magic(const int n1, std::string& str);
    std::function < void(const int, std::string&) > fn = &Magic;

    auto f1 = []() { std::cout<<"hello"; }
          |
    ------->class Lambda@1{
                Lambda();
                operator() () {
                    std::cout<<"hello";
                }
            }
            Lambda@1 fn = &f1;
    <--------
    same is for bind function
*/

/*
    void Magic() {
        std::cout<<"hello\n";
        int n1 = 10;
        std::cout<< n1 * 90;
    }

    std::function<void ()>
*/