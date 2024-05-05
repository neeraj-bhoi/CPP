// #include<bits/stdc++.h>
#include<iostream>
#include<new>
using namespace std;

int main() {
    cout<<"main started...\n\n";
    int x;
    int *xp = new int;
    
    try {
        xp = new int[100000000000000];
    } catch(bad_alloc ba) {
        cout << "Heap memory allocation error"<<endl;
    }
    x = 100;
    *xp = x;
    cout<<"*xp = "<<*xp<<"  x = "<<x<<endl;


    cout<<"\n\nmain ended....";
    return 0;
}






//**************************************
// badtype 
// badcast