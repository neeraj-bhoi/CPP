/*
    triggers app
    f1----------------->f2(2 integers will be created)
                        |
                        |
                        |
                        |
                        Predicate to filter the data
*/
#include<iostream>
#include<functional>
#include<vector>

std::function<int()> f2(int n1, int n2) {
    // auto lambda_fn = [](int n1, int n2) {return n1 + n2;};
    //lambda can capture data from its enclosing function without explicit passing

    // auto lambda_fn = [](int& n1, int& n2) {return n1 + n2;};
    //another way compiles and runs but doesn't justify the purpose(because of closure, )

    auto lambda_fn = [ & ]() { int val = 99; return n1 + n2 + 10 + 20 + val; };
    //                 | 
    //       /* CAPTURE CLAUSE*/
    lambda_fn();

    return lambda_fn;  //-->CLOSURE (wherever this goes it will contain the data in the function)
}

void f1(){
    int n1 = 10;
    int n2 = 20;
    std::function<int()> modified_function = f2(n1, n2);
    std::cout<< modified_function() <<"\n";
}

void trick() {
    int n1 = 100;
    auto f1 = [=] () mutable {n1 = 999;};

    f1();
    std::cout<<n1<<"\n";
    // if passed as copy then cannot change the value...
    // mutable is used to be able to do that

    // std::cout<<n1; // value = 100
}

int main() {
    trick();
}

/*
    main fn in stack memory{

    }

    f1 stack memory{
            n1         n2
            [10]       [20]
            0x1H        0x2H
    }


    f2{
            n1         n2        lambda_fn  (an object of class lambda in local scope)     
            [10]      [20]      [............] 
            0x45H     0x56H     0x77H
                                    |
                                    |
                                    |
                                    |
                                {
                                    n1          n2      //this should not happen
                                }                       //lambda can capture data from its enclosing function without explicit passing    
    }

*/

/*
void Magic() {
        int n1 = 10;
        int n2 = 20;
        int n3 = 30;
                {
                    example1 : all data vlaues from "enclosing function" are accessible inside f1
                }    
        auto f1 = [&]() { return n1 + n2; };

                {
                    example2 : selected data values capture by copy
                }
        auto f1 = [n1]() { return n1 + n2; };

                {
                    example3 : selected data values capture by copy
                                both are accessible as copies
                }
        auto f1 = [n1, n2]() { return n1 + n2; };

                {
                    example4 : selected data values capture by copy
                                both are accessible as references
                }
        auto f1 = [&n1, &n2]() { return n1 + n2; };

                {
                    example5 : all data values capture by copy
                }
        auto f1 = [=]() { return n1 + n2; };

                {
                    example6 : some data values capture by copy, some by reference
                }
        auto f1 = [n1, &n2, &n3]() { return n1 + n2; };
            //n1 as copy, n2 & n3 as references
}
*/



