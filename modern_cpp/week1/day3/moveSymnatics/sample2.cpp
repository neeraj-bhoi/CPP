#include<iostream>
#include<vector>

// Magic function that accepts 1 stud(standerd) vector of integers by value
// magic returns void
void Magic(std::vector<int> data) {

}

int main() {
    Magic(std::vector<int> {1, 2, 3, 4, 5});    //move assignment
    // the temporary memory is formed in the registers and directly transfered to Magic
    // but Compilers/registers are smart and directly transfers data to Magic
    // motive is that main at no point stores this value

    /*ABOVE LINE MEANS
        std::vector<int> data = std::vector<int> {1, 2, 3, 4, 5}; (in Magic)
    */

    std::vector<int> v1 = {1, 2, 3, 4, 5};
    Magic(v1);
    // magic can accept both lvalue and rvalue


}

