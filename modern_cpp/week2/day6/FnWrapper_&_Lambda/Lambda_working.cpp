#include<iostream>

class LambdaImplementation
{
private:
    int _number;        // to be dicsussed..
public:
    LambdaImplementation() = default;
    ~LambdaImplementation() = default;

    //function call () operator --- [paren paren]{us wale bulate hain}
    void operator()(int number) {
        std::cout<<"Square of :"<<number<<" is : "<<number * number<<"\n";
    }
    void display(int number) {
        std::cout<<"hello";
    }
};

int main() {
    LambdaImplementation l1;
    l1(10);     // () operator called       //this is what lambda function is...

    LambdaImplementation l2;
    l2.display(1);
    /*
        compiler creates an object of class and calls operator in background
        we write auto because we can't know the name of the class...
    */
}