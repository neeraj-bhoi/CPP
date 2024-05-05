/*

*/

#ifndef STACK_HPP
#define STACK_HPP

#include<iostream>
#include<list>
#include "StackEmptyException.hpp"

template <typename T>
class Stack
{
private:
    std::list<T> _data{};

    
public:
    Stack() = default;
    // Stack(int i) {
    //     _data.push_back(i);
    // }

    Stack(const Stack&) = delete;
    Stack& operator=(const Stack&) = delete;

    Stack(Stack&&)= default;
    Stack& operator=(Stack&&) = default;

    ~Stack() = default;

    void Pop();
    void Push(T val);
    T Peek();
    size_t Size();
    bool IsEmpty();
};


#endif // STACK_HPP


/*
    IMPLEMENTATIONS
*/

template <typename T>
inline void Stack<T>::Pop()
{
    if(_data.empty()) {
        throw StackEmptyException("data is empty");
    }
    _data.pop_back();
}

template <typename T>
inline void Stack<T>::Push(T val)
{
    // push accepts one item "val"
    // returns void
        _data.push_back(val);

}

template <typename T>
inline T Stack<T>::Peek()
{
    if(_data.empty()) {
        throw StackEmptyException("data is empty");
    }
    return _data.back();
}

template <typename T>
inline size_t Stack<T>::Size()
{
    return _data.size();
}

template <typename T>
inline bool Stack<T>::IsEmpty()
{
    // if(_data.empty()) {
    //     return true;
    // } else {
    //     return false;
    // }
    return _data.empty();
}
