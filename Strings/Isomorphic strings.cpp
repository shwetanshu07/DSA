/*
Given two strings 'str1' and 'str2'
check if these two strings are isomorphic to each other.

Input:
str1 = aab
str2 = xxy
Output: 1
*/

#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;

bool areIsomorphic(string str1, string str2)
{
    // return false if the lengths are different
    if(str1.length() != str2.length()){
        return false;
    } 

    // if same do something
    unordered_map<char, char> map;
    unordered_set<char> set;
    for(int i=0; i<str1.length(); i++){
        char first = str1[i];
        char second = str2[i];
        if(map.find(first)==map.end() && set.find(second)==set.end()){
            // add those values
            map.insert({first, second});
            set.insert(second);
        }
        else if(map.find(first)==map.end() && set.find(second)!=set.end())
        {
            return false;
        }
        else{
            // check if the values are same
            if(map[first] != second) return false;
        }
    }
    return true;
    
}


int main(){
    string str1 = "pijthbsfy";
    string str2 = "fvladzpbf";
    cout<<"String 1 = "<<str1.length()<<endl;
    cout<<"String 2 = "<<str2.length()<<endl;
    bool result = areIsomorphic(str1, str2);
    cout<<result;
    return 0;
}
