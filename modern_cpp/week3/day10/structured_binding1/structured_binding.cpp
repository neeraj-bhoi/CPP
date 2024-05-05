#include<iostream>
#include<array>
#include<unordered_map>

int main() {
    std::array<int, 2> data{101, 90000};
    // int empId = data[0];
    // int empSalary = data[1];

    // alternative

    auto [empId, empSalary] = data; //structured Binding [cpp17]
    // auto&[empId1, empSalary1] = data;

    std::unordered_map<int, std::string> map {
        std::make_pair<int, std::string>(101, "harshit"),
        std::make_pair<int, std::string>(102, "rikshit")
    };

    for(auto& [k,v] : map) {
        std::cout<<"key is : "<<k<<" value is : "<<v<<"\n";
    }

}

/*
    structured binding
    this which are of fixed size and stored consecutively
*/