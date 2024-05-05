#include<iostream>
#include<vector>
#include<functional>    //support for functional programming !!!
/*   instead of pointer of array -> vector   */


// void Square(int number) {
//     std::cout<<"Square of :"<<number<<" is : "<<number * number<<"\n";
// }

void Cube(int number) {
    std::cout<<"Cube of :"<<number<<" is : "<<number * number * number<<"\n";
}

//Higher order function
//either accepts/returns/both another function
void operation(const std::vector<int>& data, std::function<void(int)> fn) {   //function wrapper  *******
    for(int val : data) {     //   |-----------------------------------> this function can take both l/rvalue
        fn(val);
    }
}

int main() {
    //fn pointer

    std::vector<int> data {10, 20, 30, 40, 50};
    operation(
        data,
        [](int number) -> void{                                     //LAMBDA FUNCTION       ********
            std::cout<<"Square of :"<<number<<" is : "<<number * number<<"\n";
        }
    );    

    //auto because you can't guess the type of lambda functioan
    auto cube = [](int number) -> void{            //not a good use of lambda, but possible                               
            std::cout<<"Square of :"<<number<<" is : "<<number * number * number<<"\n";
        };

    operation(data, cube); 

}


/*
    [](int number) -> void{                                           //LAMBDA FUNCTION       ********
            std::cout<<"Square of :"<<number<<" is : "<<number * number<<"\n";
    }

    Lambda functions : this is an rvalue..
        -one time use and throw logic, which does not need to be stored
        -to limit the scope of function
        -sometimes the function is so short that making a saperate block for it is a waste of space

    [] -> captore clause
    used for creating lambda closure..
*/