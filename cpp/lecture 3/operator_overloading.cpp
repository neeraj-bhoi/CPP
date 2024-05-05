#include<bits/stdc++.h>
using namespace std;

class mystring {
    char* cptr;
    int dist;

    public :
        mystring() {
            cptr = new char;
            *cptr = '\0';
        }
        mystring(const char* cptr) {
            int len;
            len = strlen(cptr);
            this -> cptr = new char[len+1];
            strcpy(this -> cptr, cptr);
        }

        void display() {
            cout<<cptr<<endl;
        }

        //operator overloading
        mystring operator + (mystring &s) {
            mystring temp = NULL;

            int len1 = strlen(this -> cptr);
            int len2 = strlen(s.cptr);

            // allocate memory for resulting string(concatenation of two strings)
            temp.cptr = new char(len1 + len2 + 1);

            //transfer characters from both strings to allocated memory
            strcpy(temp.cptr, this -> cptr);
            strcat(temp.cptr, s.cptr);

            return temp;
        }
};

int main() {
    mystring s1("c++"), s2("programming");

    s1.display();
    s2.display();

    mystring s3;
    s3 = s1 + s2;
    // s3 = 

    s3.display();

    return 0;
}