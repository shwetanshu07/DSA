/* Reverse the words in a given string
I/P -> hello world
O/P -> world hello
*/

#include <iostream>
using namespace std;

void reverse(string &str, int start, int end){
    while(start<end){
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

/* Reverse each word first then reverse the whole string*/
void method_2(string &str){
    int start = 0;
    int end = 0;
    for(; end<str.size(); end++){
        if(str[end]==' '){
            reverse(str, start, end-1);
            start = end+1;
        }
    }
    // now start is at the begining of end word and
    // end is equal to the last letter of the end word
    reverse(str, start, end-1);
    reverse(str, 0, end-1);
}

int main(){
    string str = "hello world";
    method_2(str);
    cout<<str<<endl;
    return 0;
}
