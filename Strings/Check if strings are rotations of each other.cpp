/*
Given two strings s1 and s2. The task is to check if s2 is a rotated version
of the string s1. The characters in the strings are in lowercase.

Input:
s1 = geeksforgeeks
s2 = forgeeksgeeks
Output: 1
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> lpscalculate(string pat, int m){
    vector<int> lps(m);
    int i=1, j=0;
    lps[0] = 0;
    while(i<m){
        if(pat[i] == pat[j]){
            lps[i] = j+1;
            i++;
            j++;
        }
        else{
            if(j!=0) j = lps[j-1];
            else{
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

bool substringcheck(string txt, string pat){
    int n = txt.length();
    int m = pat.length();
    vector<int> lps = lpscalculate(pat, m);
    int i=0, j=0;
    while(i<n){
        if(txt[i]==pat[j]){
            i++;
            j++;
        }
        else{
            if(j!=0) j = lps[j-1];
            else i++;
        }
        if(j==m){
            return true;
        }
    }
    return false;
}

int main(){
    string str1 = "geeksforgeeks";
    string str2 = "forgeeksgeeks";

    if(str1.length()!=str2.length()) cout<<0;

    else{
        string str = str1+str1;
        //check if str2 is a substring of str
        bool result = substringcheck(str, str2);
        if(result==true) cout<<1;
        else cout<<0;

    }
    return 0;
}
