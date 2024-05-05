#include<iostream>
class a{
    public:
     int i{1};
     int j{2};
     int k{3};
};
int main(){
    a o1;
    auto[k,l,m]=o1;
    std::cout<<k<<l<<m;
    return 0;
}