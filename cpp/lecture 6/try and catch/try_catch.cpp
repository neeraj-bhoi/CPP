#include<bits/stdc++.h>
using namespace std;

int accept() {
    int num;
    cout<<" enter number : ";
    cin>>num;
    return num;
}

void divide(int a, int b) {
        double d = a / b;
        cout<<" the result of division is : " << d << endl;
}

int main() {

    // cout<< "\n\nmain started ...." << endl;

    // int x = 0;

    // try {
    //     cout << "Entered in try block .... " << endl;
    //     x = 500;
        
    //     if ( x >= 100) {
    //         throw x;
    //     }

    //     cout << "this statement is at the end of try block ... " << endl;
    // } catch (int z){
    //     cout<< "Entered in catch block ....  z = " << z << endl;
    // }

    // cout << "main ended .... " << endl;


///////////////////////////////////////////////////////////


    cout<<"main started ............... " << endl;
    int a;
    int b;

    while (true) {
        try {
            a = accept();
            b = accept();
            if(b == 0) throw b;
            divide(a, b);
            break;
        } catch (int z) {
            cout<< " cannot divide by " << z<< endl;

            char response;
            cout<<" do you want to contunue (y/n) :";
            cin>>response;
            if(response == 'y' || response == 'Y') {
                continue;
            } else {
                break;
            }
        }
    }


    return 0;
}