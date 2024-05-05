// #include <iostream>
// #include<bits/stdc++.h>
// #include<unistd.h>
// using namespace std;

// int main()
// {


//     int i = setuid(0);
//     printf("setuid: %d  , e: %d\n", i, errno);

//     int j = getuid();
//     printf("getuid: %d\n", j);

//     cout << "Hello World!" << endl;

//     FILE *fp = fopen("nkb.txt", "w");
//     if(fp) {
//         fprintf(fp, "nkb");
//         getchar();
//         fclose(fp);
//     } else {
//         printf("failed");
//     }
//     return 0;
// }


// #include<bits/stdc++.h>
// using namespace std;

// int isprime(int n) {
//     for(int i = 2; i*i < n; i++) {
//         if(n % i == 0) {
//             return 0;
//         }
//     }
//     return 1;
// }

// int main() {


//     //FIBONACCI
//     // int a = 0;
//     // int b = 1;
//     // int n;

//     // cout<<"enter how many numbers to print :: ";

//     // cin>>n;
//     // cout<<0<<" "<<1;
//     // for(int i = 2; i < n; i++) {
//     //     int c = a + b;
//     //     a = b;
//     //     b = c;
//     //     cout<<" "<<c;
//     // }
//     // return 0;


//     //PRIME NUMBER


//     int i = 2;
//     while(1) {
//         if(isprime(i++) == 1) {
//             cout<<i<<endl;
//             // getch();
//         }
//     }
//     return 0;
// }

//////////////////////////////////////////////////////////
//prasoon


//dyanamic allocaation

// #include <bits/stdc++.h>

// using namespace std;
// struct ans{
//     float avg;
//     int total;

// }s;
// ans f(int a){
//     int *arr = new int[a];
//     for(int i=0;i<a;i++){
//         cin>>arr[i];
//     }
//     ans temp;
//     int tavg = 0;
//     for(int i=0;i<a;i++){
//         tavg = tavg + arr[i];
//     }
//     int tsum = 0;
//     for(int i=0;i<a;i++){
//         tsum = tsum + arr[i];
//     }
//     temp.total = tsum;
//     temp.avg = tavg/5;

//     return temp;
// }
// int main()
// {
//     // malloc(10);
//     // return 0;
//     ans c = f(5);
//     cout<<"Avg of nummbers"<<c.avg<<endl;
//     cout<<"Sum of nummbers"<<c.total<<endl;

//     // int x,y,z;
//     // cin>>x>>y>>z;
//     // cout<<"Avg of given numbers "<<(x+y+z)/3;

//     //prime number
//     // int n;
//     // cin>>n;
//     // int f = 0;
//     // for(int i=2;i<n;i++){
//     //     if(n%i == 0){
//     //         f = 1;
//     //     }
//     // }
//     // if(f){
//     //     cout<<"Not prime number";
//     // }
//     // else{
//     //     cout<<"Prime NUmber";
//     // }

//     //fibonaccii series
//     // int prev = 0;
//     // int curr = 1;
//     // cout<<prev<<" ";
//     // cout<<curr<<" ";
//     // for(int i=0;i>=0;i++){
//     //     int next = prev + curr;
//     //     prev = curr;
//     //     curr = next;
//     //     cout<<next<<" ";
//     // }

//     // // setuid(0);
//     // FILE *fp = fopen("prasoon.txt","w");
//     // if(fp){
//     //     fprintf(fp,"prasoon");
//     //     getchar();
//     //     fclose(fp);
//     // }
//     // else{
//     //     printf("failed");
//     // }
//     // cout << "Hello World!" << endl;
//     return 0;
// }



//str
// #include<iostream>
// #include<unistd.h>
// #include<sys/mman.h>
// using namespace std;

// int main() {
//     char *str = "asif";


//     size_t addr = (size_t)str;
//     getchar();
//     addr = addr&0xfffffffffffff000l;
//     mprotect((void*)addr, 10, PROT_READ | PROT_WRITE | PROT_EXEC);
//     // char* ptr = str;
//     // *str = 'd';

//     cout<<getpid()<<":"<<addr<<endl<<flush;

//     str[0] = 'd';
//     cout<<str;

//     return 0;
// }



#include<bits/stdc++.h>
using namespace std;

int main() {
    malloc(0x100);

    return 0;
}


