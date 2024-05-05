#include<bits/stdc++.h>
#include<sys/mman.h>
#include<unistd.h>
using namespace std;

char *readfile() {
    FILE *fp = fopen("a.txt", "r");
    if(fp) {
        char *buffer = (char*)malloc(100);
        fgets(buffer, 100, fp);
        fclose(fp);
        return buffer;
    }
    return nullptr;
}

bool g_con = true;

void notifyuser(void (*p)()) {
    while(g_con) {
        char *str = readfile();
        if(strstr(str, "sub")) {
            cout<<"found\n";
            p();
        }

        free(str);
        sleep(1);
    }
}

void user() {
    cout<<"notified";
    g_con = false;
}

void addMatrices(int (*matrix1)[10], int (*matrix2)[10], int (*result)[10]) {
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

int main() {


    int a[10][10];
    int (*p)[10] = a;
    notifyuser(user);

    return 0;
}