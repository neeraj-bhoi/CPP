#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include<bits/stdc++.h>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 * ---
 * Hint: You can use the debug stream to print initialTX and initialTY, if Thor seems not follow your orders.
 **/

int length(char str[]) {
    int count = 0;

    for(int i = 0; ; i++) {
        if(str[i] == '\0'){
            break;
        }
        count++;
    }

    return count;
}

void reverse(char str[], int len) {
    for(int i = 0; i < (len-1)/2; i++) {
        swap(str[i], str[len - 1 - i]);
    }
}

int main()
{
    char str1[] = "hiiiiiiiii";
    int len1 = length(str1);

    char str2[] = "helooooooo";
    int len2 = length(str2);

    reverse(str1, len1);
    cout<<str1;

}
