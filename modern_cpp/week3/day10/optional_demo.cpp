#include<iostream>
#include<vector>
#include<optional>


// developer part : what is the API? what is the design? corner case ?

/*
    std::vector<int> result;
    try{
        result = FindOddNumbers(data);
    } catch(const std::exception& ex) {
        std::cout<<ex.what()<<"\n";
    }
    if(!result.empty()) {
        for(int val : result) {
            std::cout<<val<<"\n";
        }
    } else {
        std::cout<<"no odd numbers";
    }
    problem : so many if's and conditions
        scenarios:
            -my input has atleast 1 value & some values are odd 
                [will return something]
            -my input has atleast 1 value & none values are odd 
                [may or may not return something]                   **********
            -my input is empty : nothing will work
                [not my concern. invalid input. exception]
solution : std::optional
    indicates an algebric data type that may :
        -either contain a valid value
        -or a symbol indicating "absence of information"
        |
        |
        |
*/

std::optional<std::vector<int>>FindOddNumbers(std::vector<int>& data) {
    std::vector<int> result;

    if(data.empty()) {
        // throw exception
    }

    for(int val : data) {
        if(val % 2 != 0) {
            result.push_back(val);
        }
    }

    if(result.empty()) {
        return std::nullopt;
    }

    return result;  // check cornor cases before this
}

/*
    caller : the user who invokes or calls the functionality or accesses the API
*/
int main() {
    std::vector<int> data{10, 10, 10, 40, 50, 60, 70};
    FindOddNumbers(data);

    /*
       //IF INITIALIZATION SYNTEX {cpp17 onwards}
        if(std::vector<int> result = FindOddNumbers(data); !result.empty()) {
            for(int val : result) {
                std::cout<<val<<"\n";
            }
        }
    */

    std::optional<std::vector<int>>result;

    try{
        result = FindOddNumbers(data);
    } catch(std::runtime_error& ex) {
        std::cout<<ex.what()<<"\n";
    }

    if(result.has_value()) {
        std::cout<<result.value()[0];
    }

}
