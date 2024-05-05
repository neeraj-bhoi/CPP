#include<iostream>


/* TYPE - 1*/

// int main() {
//     float f1 = 10.21f;
        
//     /*C-STYLE CAST*/

//     int n = (float) f1;    // lossy conversion
//     //int n1 = (float) "neeraj";    // invalid type conversion

//     /* we cant keep a condition if cast is successfully working or not
//             if(//cast works) : do something
//             else : do something...
//     */

//    //to correct this STATIC - CAST
//    int n1 = static_cast<int>(f1);
//     //    static_assert()
//    /*use static cast in any case of casting until dyanamic polymorphism*/

//     // std::cout << n1 << "\n"; 
// }


/*TYPE - 2*/
// to do dynamic cast at-least one virtual function needs to be there in parent class
//base class destructor must be marked virtual if upcasting is used...
    // else (child destructor will never get called)

    //dynamic cast is required when
        // inheritence
        // upcasting
        // a function in derived class not available in parent class
class parent
{
private:
    /* data */
public:
    parent(/* args */) {}
    virtual ~parent() {}

    virtual void magic() = 0;
};

class child : public parent
{
private:
    /* data */
public:
    child(/* args */) {}
    virtual ~child() {}

    void childDisplay() { std:: cout<< "Done!\n"; }
    void magic() override {std:: cout<< "magic from child!\n"; }
};

int main() {
    /*TYPE-2
        cast when parent-child runtime polymorphism is in picture

        2a)converting reference

        2b)converting pointer

    */

   //2a)converting reference
    parent* ptr = new child();
    try {
        child& ch = dynamic_cast<child&> (*ptr);//dyanamic method dispatch
        // dyanamic method dispatch occurs after late binding.

        ch.childDisplay();

    } catch(std::bad_cast& ex) {
        // do something about it....
    }


   //2b)converting pointer : if conversion fails, we get nullptr
     //parent* ptr = new child(); //upcasting
    ptr -> magic();     //ptr type is parent. function in virtual

    // ptr -> childDisplay();  //it will show error..
    child* temp = dynamic_cast<child*> (ptr);
    if(temp != nullptr) {               // check
        temp -> childDisplay();
    }




}