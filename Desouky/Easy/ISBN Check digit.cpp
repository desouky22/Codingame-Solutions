#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define ll long long
#include <bits/stdc++.h>
using namespace std;

bool isValidTen(string s){
    int val = 10;
    ll ans = 0;
    for(int x = 0; x<9; x++){
        ans += (s[x]-'0') * val--;
    }
    
    ans = ans % 11;
    if(ans != 0){
        ans = 11 - ans;
    }

    if(ans != 10){
        if(s[s.size()-1] == char(ans+'0'))return true;
        else return false;
    }else{
        if(s[s.size()-1] == 'X')return true;
        else return false;
    }
    return false;
}


bool isValid13(string s){
    ll ans = 0;
    for(int x = 0; x<s.size()-1; x++){
        if(x%2 == 0) ans += (s[x]-'0') * 1;
        else ans += (s[x]-'0') * 3;
    }
    ans = ans % 10;
    if(ans != 0){
        ans = 10 - ans;
    }
    if(s[s.size()-1] != char(ans+'0'))return false;
    else return true;
}

int main()
{
    int n;
    cin >> n; cin.ignore();
    vector<string>v;
    int invalid = 0;
    for (int i = 0; i < n; i++){
        string isbn;
        getline(cin, isbn);
        if(isbn.size() == 10){
            if(!isValidTen(isbn)) {v.push_back(isbn);}
        }else if(isbn.size() == 13){
            if(!isValid13(isbn)) v.push_back(isbn);
        }else {
            v.push_back(isbn);
        }
    }
    cout<<v.size()<<" invalid:\n";
    for(auto it: v){
        cout<<it<<"\n";
    }
}
