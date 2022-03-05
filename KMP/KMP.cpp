#include <bits/stdc++.h>
using namespace std;

int findNeedleInHay(string hay, string needle) {
    if(needle.length() == 0)
        return 0; 
    vector<int> failure = buildFailure(needle); 
    for(int i = 0, j = 0; i<hay.length(); i++){
        while(j != 0 && hay[i] != needle[j])
            j = failure[j-1]; 
        if(hay[i] == needle[j]){
            j++; 
            if(j == needle.length())
                return i-j+1;
        }
    }
    return -1; 
}

vector<int> buildFailure(string str){
    vector<int> res(str.length()); 
    for(int i = 1, j = 0; i<str.length(); i++){
        while(j!=0 && str[i] != str[j])
            j = res[j-1]; 
        if(str[i] == str[j])
            j++; 
        res[i] = j; 
    }
    return res; 
}