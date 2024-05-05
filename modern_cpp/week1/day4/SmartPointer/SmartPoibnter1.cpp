#include<iostream>   
#include<memory>    //for smart pointer

class Example1
{
private:
    std::string _name;
    int _id;
public:
    Example1(int id, std::string name) :_id(id), _name(name){}

    

    ~Example1() {}
};

void Dummy() {
    
    // std::shared_ptr<Example1> sptr {new Example1(10, "harshit")};                //1st way
    std::shared_ptr<Example1> sptr {std::make_shared<Example1> (10,  "harshit")};   //2nd way


/////////////////////////////////
    // Example1* ex1;

    int n1 {0};

    std::cin>>n1;
    std::cout<<10/n1;   //exception thrown if n1 == 0
    /*
    
    */
    // delete ex1;     //problem here(if exception is thrown this line will not execute)
                    //this problem is solved by SMART POINTERS
}

int main() {
    try {
        Dummy();
    } catch(std::exception& ex) {

    }
}



/*
    Dummy() 
        
        ex1                 ------->            heap
        [ 0x100H ]              ----------->[10 | Harshit]
        <----8 bytes--->        ----------->  0x100H
        0x11H -----0x18H

        n1
        [ 0 ]
        <----4 bytes--->
        0x45H ----- 0x48H

*/


/*
    data : pointer ex1
    function which is guaranteed to execute each timean object is destroyed: destructor
    action before date(ex1) is destroyed : heap deallocation using delete ex1

    {Basically this is what a SMART POINTER is}


    Smart pointers:
        1) unique pointer
        2)shared pointer
        3) weak pointer(token which can convert to shared ptr)
*/

