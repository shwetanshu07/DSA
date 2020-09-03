/*Given two strings a and b. The task is to find if the string 'b' can be
obtained by rotating another string 'a' by exactly 2 places.

Input:
a = amazon
b = azonam
Output: 1

*/

#include <iostream>
using namespace std;

void reverse(string &s, int start, int end){
    while(start<end){
        char temp = s[start];
        s[start] = s[end];
        s[end] = temp;
        start++;
        end--;
    }
}

bool isRotated(string a, string b){

    if(a.length()==1 && b.length()==1 && a==b) return true;

    string leftstr = a;
    string rightstr = a;
    int k = 2;
    int last = a.length()-1;

    // check for left rotation
    reverse(leftstr, 0, last);
    reverse(leftstr, 0, last-k);
    reverse(leftstr, last-k+1, last);

    // check for right rotation
    reverse(rightstr, 0, last);
    reverse(rightstr, 0, k-1);
    reverse(rightstr, k, last);

    if(leftstr==b) return true;
    else if(rightstr==b) return true;
    else return false;
}

int main(){
    string a = "amazon";
    string b = "azonam";

    //string a = "d";
    //string b = "d";

    bool result = isRotated(a, b);
    cout<<result;
    return 0;
}
