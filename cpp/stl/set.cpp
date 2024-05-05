// #include <iostream>
// #include <set>
 
// int main()
// {
//     std::set<char> a;
//     a.insert('G');
//     a.insert('F');
//     a.insert('G');
//     for (auto& str : a) {
//         std::cout << str << ' ';
//     }
//     std::cout << '\n';
//     return 0;
// }




#include <iostream>
#include <set>
using namespace std;
 
int main()
{
 
    set<int, greater<int> > s1;
    s1.insert(10);
    s1.insert(5);
    s1.insert(12);
    s1.insert(4);
 
    for (auto i : s1) {
        cout << i << ' ';
    }
    return 0;
}