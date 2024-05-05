#include<bits/stdc++.h>
using namespace std;

void Xhandler() {
    // throw "hiiiii";

    try {
        throw "This is one message. ";
    } catch(const char* m) {
        cout<<"Catch block... "<<m<<endl;
        throw "exception is thrown";        //rethrowing exception
    } catch(...) {
        cout<<"default catch..."<<endl;
    }
}

int main() {

    try {
        cout<<"Try block..."<<endl;
        Xhandler();
        throw "exception is thrown";
    } catch(const char* msg) {
        cout<<"Catch block... "<<msg<<endl;
    } catch(...) {
        cout<<"default catch..."<<endl;
    }


    cout<<"\n\nmain ended........";
    return 0;
}