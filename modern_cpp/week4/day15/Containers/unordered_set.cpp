#include<iostream>
#include<unordered_set>

int main() {
    std::unordered_set<int> s1 {11, 12, 11, 13, 11, 14};

    auto pair = s1.insert(15);

    if(pair.second) {
        std::cout<<"element added ...\n";
    } else {
        std::cout<<"element not added ...\n";
    }
}