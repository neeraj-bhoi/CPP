#include<iostream>

class dummy{
    private:

    public:
        dummy() noexcept;
        void Display() noexcept {
            std::cout<<"hello!!!"<<"\n";
            throw 1;
        }
};

int main() {
    dummy d1;
    d1.Display();
}


/*

    case1:
        no exception

    case2:
        exception thrown(default setting)
            code compiles with warning

    case3:
        exception thrown(with -Werror and -Wextra)
            compile time error
*/