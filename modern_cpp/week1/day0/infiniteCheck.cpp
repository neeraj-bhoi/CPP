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

int main() {

    notifyuser(user);

    return 0;
}