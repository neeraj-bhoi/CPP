#include <iostream>
    using namespace std;
    class sample
    {
        public:
        virtual void example() = 0; 
    };
    class Ex1:public sample
    {
        public:
        void example()
        {
            cout << "ubuntu";
        }
    };
    class Ex2:public sample
    {
        public:
        void example()
        {
            cout << " is awesome";
        }
    };
    int main()
    {
        sample* arra[2];
        Ex1 e1;
        Ex2 e2;
        arra[0]=&e1;
        arra[1]=&e2;
        e1.example();
        arra[1]->example();
    }