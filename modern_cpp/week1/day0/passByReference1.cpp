#include<sys/mman.h>
#include<bits/stdc++.h>
using namespace std;

void printtoscreen(char *str) {

}

void printtofile(char *str) {

}

void printdata(void (*ptr)(char *)) {

    printf("%llx\n",printdata);fflush(stdout);
    char data[10] = "1234";
    //char *data = "1234";
    data[2] = '6';
    ptr(data);
}

int main() {
    printdata(printtoscreen);
    return 0;
}