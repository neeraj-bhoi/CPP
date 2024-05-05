#include<iostream>
#include<vector>


/*
    no.        Identifier-name         Address     content         Alternate names
    1           n1                     0x99H           99              ref, argRef
    2           data                   0x187H           10              r1, r2
*/
void Magic(int& argRef) {

}

int main() {
    int n1 = 99;
    int &ref = n1;     //creating a reference

    
    int& ref2 = ref;
    std::cout<<ref--;
    std::cout<<"\n"<<n1--;
    std::cout<<"\n"<<ref2;

    Magic(n1);          //pass by reference
    // references ka container nahi banta...

    int arr[] = {1, 2, 3};
    // int& arr1[] = {n1};  //error
    /*
        a reference does not exist enywhere in memory
        alternate name for something does not exist in memory
        references do not hold memory so they cannot be treated like value
    */

    // std::vector<int&> values{ref};
    //while compiling it gives error(if not in the vscode editor)

    //    problem2
    // reference ka reference dikkat dega
    int data = 10;
    int& r1 = data;
    int& r2 = r1;

    std::cout<<"\n\n"<<data<<"  "<<r1<<"  "<<r2;
    // reference ko class me daalke access kr sakte hain
    // which basically is reference wrapper.
    // each object of reference wrapper class will hold a single reference.
    /*
        previously:
            a pointer when stored internally in an object
            creates representation of a pointer(smart pointer)
        now:
            A reference stored in an object internally creates representation of a
            reference calles reference_wrapper
    */


}

/*
    fn(int a);

    fn(10);  ---------->      int a = 10;
*/