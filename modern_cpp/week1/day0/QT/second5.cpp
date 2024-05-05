#include <iostream>
#include<bits/stdc++.h>
#include<stdlib.h>
#include<X11/Xlib.h>
#include<X11/Xutil.h>
#include<sys/mman.h>
#include<unistd.h>
using namespace std;

// bool g_con = true;

// void notifyuser(void (*p)()) {
//     while(g_con) {
//         char *str ;
//         if(strstr(str, "sub")) {
//             cout<<"found\n";
//             p();
//         }

//         free(str);
//         sleep(1);
//     }
// }

// void user() {
//     cout<<"notified";
//     g_con = false;
// }

void notify() {
    cout<<"notified";
    return;
}

void checknamecallout(void (*notify)()) {

    // vector<char>vec;
    // while(1){
    //     char c;
    //     cin>>c;
    //     vec.push_back(c);

    //     //check
    //     if(vec[vec.size() - 1] == 'f' && vec[vec.size() - 2] == 'i' && vec[vec.size() - 3] == 's' && vec[vec.size() - 4] == 'a') {
    //         //notify
    //         notify();
    //     }
    // }
}



int find(vector<char> vec) {
    if(vec[vec.size() - 1] == 'f' && vec[vec.size() - 2] == 'i' && vec[vec.size() - 3] == 's' && vec[vec.size() - 4] == 'a') {
        return 1;
    }
    return 0;
}
int main()
{
    // Display *d = XOpenDisplay(NULL);//call this only once;
    // //     //keymap testing
    // char nk[32] = "";
    // while(1) {
    //     XQueryKeymap(d, nk);
    //     for(int i = 0; i < 256; ++i) {
    //         cout<<i<<":"<<(int)nk[i]<<",";
    //     }
    //     cout<<endl;
    // }
    // return 0;
    // checknamecallout();


    vector<char>vec;
    while(1){
        char c;
        cin>>c;
        vec.push_back(c);

        //check
        if(find(vec) == 1) {
            //notify
            notify();
        }
    }

    return 0;
}
