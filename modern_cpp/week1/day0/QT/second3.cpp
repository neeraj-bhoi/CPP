#include <iostream>
#include<bits/stdc++.h>
#include<stdlib.h>
#include<X11/Xlib.h>
#include<X11/Xutil.h>
using namespace std;



int main(int args, char*p[], char **env)
{

//     // cout << "Hello World!" << endl;

//     // {
//     //     cout<<p[0]<<endl;

//     //     for(int i = 0; ; ++i) {
//     //         if(env[i])
//     //             cout<<env[i]<<endl;
//     //         else
//     //             break;
//     //     }
//     // }

//     cout<<getenv("COLORTERM");
//     return 0;


    Display *d = XOpenDisplay(NULL);//call this only once;
    //     //keymap testing
    char nk[32] = "";
    while(1) {
        XQueryKeymap(d, nk);
        for(int i = 0; i < 12; ++i) {
            cout<<i<<":"<<(int)nk[i]<<",";
        }
        cout<<endl;
    }
}





// void GetDir(Display *d, char &dir) {
//     char nk[32] = {};
//     XQueryKeymap(d,nk);
//     for(int i = 0; ; i++) {
//         cout<<nk;
//     }
// }

// int main() {
//     char nk[32] = {};


//     for(int i = 0; ; i++) {
//         XQueryKeymap(d,nk);
//         cout<<nk;
//     }

// }
