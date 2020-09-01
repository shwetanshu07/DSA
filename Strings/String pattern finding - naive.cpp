/*
Given a string of size n return all the starting indices if you find a pattern/substring
of length m.
i/p -> string: abcabcd   pattern: abcd
o/p -> 3
i/p -> string: aaaaa    pattern: aaa
o/p -> 0 1 2
*/

#include <iostream>
#include <vector>
using namespace std;


/* Time complexity (n-m+1)*m
   Space complexity O(1) - not considering the vector output */
vector<int> naive_method_1(string &str, string &pattern){
    vector<int> vec;
    int n = str.length();
    int m = pattern.length();
    for(int i=0; i<=n-m; i++){
        int j;
        for(j=0; j<m; j++){
            if(pattern[j]!=str[i+j]){
                break; 
            }
        }
        if(j==m) vec.push_back(i);
    }
    if (vec.empty()){
        vec.push_back(-1); // if there is no matching pattern
        return vec;
    }
    return vec;
}


/* This is only for pattern having distinct characters so pattern
   like aaa will not work*/
vector<int> optimised_naive_method(string &str, string &pattern){
    vector<int> vec2;
    int n = str.length();
    int m = pattern.length();
    for(int i=0; i<=n-m;){
        int j;
        for(j=0; j<m; j++){
            if(pattern[j] != str[i+j]) break;
        }
        if(j==m){
            vec2.push_back(i);
        }
        if(j==0) i++; // there is mismatch at the first character only
        else{ // j>0 and j<m  i.e mismatch after finding some matching elements
            i = i+j;
        }
    }

    if (vec2.empty()){
        vec2.push_back(-1); // if there is no matching pattern
        return vec2;
    }

    return vec2;
}

int main(){
    string str = "abcabcd";
    string pattern = "abcd";

    //string str = "aaaaa";
    //string pattern = "aaa";

    vector<int> vec = naive_method_1(str, pattern);
    for(auto itr=vec.begin(); itr!=vec.end(); itr++) cout<<*itr<<" ";

    cout<<endl;

    vector<int> res = optimised_naive_method(str, pattern);
    for(auto itr2=res.begin(); itr2!=res.end(); itr2++) cout<<*itr2<<" ";
    return 0;
}
