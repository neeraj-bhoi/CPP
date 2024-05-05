/*

Rule1 : const is applied to the token on its imidiate left,
        if there is nothing to the left of const, apply const on the token to its imidiate right

Rule2 : pointer symbol * is considered a separate token

*/


#include<iostream>

class dummy {
    private:
    public:
        int _id;
        float _salary;
        dummy(int id, float salary) : _id(id), _salary(salary) {}
        ~dummy() = default;

        float salary() const { return _salary; }
};

int main() {

    //scenario 1 : const with non-pointer primitive variable
    const int n1 = 10;  //n1 is a constant integer
    int const n2 = 20;  //n2 is a constant integer

    // scenario 2 : pointer with primitives

    int n3 = 99;
    int n4 = 188;

    //2a
        const int* ptr = &n3; //const is applied to only int not *
        // ptr is a pointer to a constant int

        /*
            *ptr = 77;  // this will give error
            n3 = 77;    //this will not
            ptr = &n4;  //this will not too
        */

    //2b
        int * const ptr2 = &n3; //ptr2 is a const pointer.

        /*
            *ptr2 = 100;    //this is ok
            ptr2 = &n4;     //this is not
        */

    //2c
        const int * const ptr3 = &n3;   //ptr3 is a const pointer to a const integer.(combo of both)

        /*
            *ptr3 = 18;     //not ok
            ptr3 = &4;      //not ok
        */

    //scenario 3: const on a STACK object
    const dummy d1(101, 67000.0f);
    // d1._id = 3;      //cannot be done

    //there is a way to cast and change the variable(const ko hatake change kar sakte hain)

    // scenario 4: const in member funstion

    //to tell that this function is safe((getters))
    //gives const correctness

    //if an object is marked constant , only a function marked constant can access its objects
}