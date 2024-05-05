/*
    any feature is added to cpp when
    GK: 
        1) it enhances the language with a brand new feature

        2.1) it improves an existing feature
                (pointers ---> smart pointers)
        2.2) it improves an existing feature
                inspired from c language which had a drawback
                eg: enum class ..., nullptr(NULL)
*/

#include<iostream>

int main() {

    // int*ptr = NULL; //0x000H
    int*ptr = nullptr;

    /*
        NULL : 0, 0L, 0o0, 0b0000, 0x0000 etc etc...(NULL has no defined type)
        so one dedicated pointer only to be used for null pointer
            --> nullptr
    */

//    int n1 = nullptr;   // not allowed

}
