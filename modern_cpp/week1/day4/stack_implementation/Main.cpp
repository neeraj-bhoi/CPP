
#include "Stack.hpp"


int main() {
    Stack<int> s;

    s.Push(1);
    s.Push(2);

    s.Size();

    std::cout<<s.Peek()<<"\n";
    s.Pop();

    std::cout<<s.Peek()<<"\n";
    s.Pop();

    s.Pop();

    std::cout<<"this is end\n";

}