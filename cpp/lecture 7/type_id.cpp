#include<bits/stdc++.h>
#include<typeinfo>
using namespace std;

class Mybase {
    int num1;

    public :
        virtual int get_num() {
            return num1;
        }

        
};

class MyDerived : public Mybase {
    int num2;

    public :
        int get_num() {
            return num2;
        }
};


// Myclass* get_object() {

    
//     if(inpch == 'B') {
//         return new Myclass;
//     } else {
//         return new derived;
//     }
// }



int main() {


    MyDerived md;
    Mybase mb;

    MyDerived * mdptr;
    Mybase * mbptr;

    mbptr = &mb;
    mbptr = &md;

    mdptr = &md;
    mdptr = (MyDerived*)&mb; //  down-casting


//using dyanamic _ cast......

    
    mbptr = dynamic_cast<Mybase*>(&mb);

    if(mbptr) {
        cout<<"success"<<endl;
    } else {
        cout<<"error"<<endl;
    }


    mdptr = dynamic_cast < MyDerived* > (&md);      /// expression : either pointer/reference

    


    return 0;


    // // Myclass obj1;
    // // derived obj2;

    // // auto type_name = typeid(obj1).name();
    // // cout<< type_name << endl;

    // // if(typeid(obj1) == typeid(obj2)) {
    // //     cout<<"same type ... "<<endl;
    // // } else {
    // //     cout<<"different type ... "<<endl;
    // // }

    // // cout<< typeid(obj2).name()<<endl;

    // Myclass * arr[6];
    // int bcount = 0; 
    // int dcount = 0;

    // for(int i = 0; i < 6; i++) {

    //     char inpch;
    //     cout<<"Myclass / derived : (B/D) :: ";
    //     cin>>inpch;

    //     if(inpch == 'B') {
    //         arr[i] = new Myclass;
    //     } else if(inpch == 'D'){
    //         arr[i] = new derived;
    //     }

    //     // arr[i] = get_object();

    //     cout<<typeid(arr[i]).name()<<endl;

    //     if(strcmp(typeid(*arr[i]).name(), "7Myclass")) {
    //         bcount++;
    //     } else if(strcmp(typeid(*arr[i]).name(), "7derived")) {
    //         dcount++;
    //     }
    // }


    // cout<<"bcount : "<<bcount<<endl;
    // cout<<"dcount : "<<dcount<<endl;

    
    // return 0;
}