#include<bits/stdc++.h>
using namespace std;

class patterns{
    public:
    int rows;

    

    void star(){
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < i; j++){
                cout<<"*";
            }
            cout<<endl;
        }
    }

    void pyramid() {
        for(int i = 0; i < rows; i++) {

            for(int j = rows - 1; j > i; j--) {
                cout<<" ";
            }

            for(int j = 0; j <= i; j++) {
                cout<<i+j+1;
            }

            for(int j = i-1; j >= 0; j--) {
                cout<<i+j+1;
            }
            cout<<endl;
        }
    }
};


int main() {
    patterns p;
    cin>>p.rows;

    p.star();
    p.pyramid();
    return 0;
}