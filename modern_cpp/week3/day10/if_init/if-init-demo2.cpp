#include<iostream>
#include<vector>

std::vector<int> FindOddNumbers(std::vector<int>& data) {
    std::vector<int> result;

    for(int val : data) {
        if(val % 2 != 0) {
            result.push_back(val);
        }
    }

    return result;  // check cornor cases before this
}

int main() {
    std::vector<int> data{10, 10, 10, 40, 50, 60, 70};
    FindOddNumbers(data);

    /*
        std::vector<int> result = FindOddNumbers(data);
        if(result.empty()) {
            std::cout<<"empty\n";
        } else {
            for(int val : result) {
                std::cout<<val<<"\n";
            }
        }
    */

   //IF INITIALIZATION SYNTEX {cpp17 onwards}
    if(std::vector<int> result = FindOddNumbers(data); !result.empty()) {
        for(int val : result) {
            std::cout<<val<<"\n";
        }
    }
}
