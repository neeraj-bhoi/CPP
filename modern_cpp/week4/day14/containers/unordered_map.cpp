/*
    Hashtable
    key is integer (employee ID) 
    value is Employee object on stack
*/

#include<iostream>
#include<unordered_map>
#include"Employee.h"


template <typename K, typename V>
void Display(const std::unordered_map<K,V> &mapData) {
    for(auto& [key, value] : mapData) {              //keep auto& if looping over constant unordered_map
        std::cout << key <<" : " << value<<"\n";
    }
}

template <typename K, typename V>
void CreateObjects(std::unordered_map<K,V> &mapData) {
    mapData.emplace(101, Employee("harshit", 80908.0f, "Trainer", 10));
    mapData.emplace(102, Employee("rakshit", 70907.0f, "Student", 7));
}


int main() {
    std::unordered_map<int, Employee> mapData;
    CreateObjects<int, Employee> (mapData);

    Display<int, Employee> (mapData);
}









// while working on a map each entry is a pair of key and values

// the pair which you fetch is an rvalue, since it is returned from somewhere.

// which is why we need to use const lvalue reference.

// and copy constructure of pair is disabled, so & is neccessary

// we can only use a pair in paramenter using const lvalue reference.
// or rvalue reference using &&

