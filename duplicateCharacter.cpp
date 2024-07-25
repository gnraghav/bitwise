//program checks for duplicate characters in a given string.

#include <iostream>

using namespace std;
int main() {
    string s = "raghur";
    long int h=0; //used to set binary bit in a number
    int x =0;
    for (int i=0;s[i]!='\0';i++) {
        x=1; // used for masking.
        x = x << (s[i]-97);
        if ((h&x) > 0) {
            cout << "duplicate found:" << s[i];
            break;
        } else {
            h |= x;
        }
    }
    return 0;
}
