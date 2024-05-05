#include<iostream>
#include<vector>

// enum Rank {
//     FIRST,
//     SECOND,
//     THIRD
// };

// enum Gear {
//     FIRST,
//     SECOND,
//     THIRD
// };

// enum Position {
//     FIRST,
//     SECOND,
//     THIRD
// };

// void Magic(int number) {
//     std::cout<<number * number<<"\n";
// }

//////////////////////////////

// enum class Rank {
//     FIRST,
//     SECOND,
//     THIRD
// };

// enum class Gear {
//     FIRST,
//     SECOND,
//     THIRD
// };

// enum class Position {
//     FIRST,
//     SECOND,
//     THIRD
// };

// void Magic(int number) {
//     std::cout<<number * number<<"\n";
// }

int main() {
    //we cannot force the user to use enum name as a prefix
    enum Rank r1 = Rank::FIRST;   //to fix -> Rank::FIRST

    enum Gear g1 = Gear::FIRST;   //to fix -> Rank::FIRST

    //compiler should block comparision of enums of different type
    // if(r1 == g1) {      
    //     std::cout<<"OOPS!!!!\n";
    // }

    //automatic(implicit) conversion of enum to int should not happen
    // Magic(r1);



    // enum class clears all 3 problems..... 


////////////////////.AUTO./////////////////////


    /*
        for each loop
        for loop using begin and end iterator
        return type of a function
        lambda variable type
        function parameters with auro
        template parameters for lambda[c++14]
        auto&& in for loop


        BEST PRACTICES
            a) do not use auto when you have no idea what exactly will be replaced in place of auto
            b) always verify whether auto can be used where you are using it(context)
                Magic(auto n1) {        //allowed after cpp20
                                        //cannot use in cpp17 or below
                }
    */

    auto n1 = 10;    // auto can be used only if we initialize at the same time
    std::vector<int> v1 {1, 2, 3, 4, 5};
    auto itr = v1.begin();      // std::vector<int>:: itr = ve.begin();

    decltype(v1)v2 {1, 2, 3, 4, 5} // allows to fetch declared data type of something(v1 in this case)

    // jaha auto likhe waha type inference hota hai


}


