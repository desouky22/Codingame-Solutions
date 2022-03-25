#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define popCount(x) __builtin_popcountll(x)
using namespace __gnu_pbds;
ll MOD = 1e9 + 7;
const int N = (int) 1e6;
#define el '\n'
#define Peow_peow ios::sync_with_stdio(0), ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
ll sum (string num) {
    ll ans  =0 ;
    for(int i = 0 ; i<num.size() ; i++) { 
        ll t= (num[i]-'0'); 
        ans += t*t; 
    }
    return ans;
}
bool IsHappyNum(string num , set<string> &st ) {
    
    string cur = to_string(sum(num));
    int cnt = 0;
    while (sum(cur) != 1LL && cnt < 1000) {
       cur = to_string(sum(cur));
       cnt++;
    }
    return sum(cur) == 1;
}
int main() {
    Peow_peow
    int t; cin>>t; 
    while(t--) { 
    string num ; cin>>num; 
     
    set<string> st;
    bool res = IsHappyNum(num, st);
    if (res) {
        cout<<num<<" :)"<<endl;
    } else {
        cout<<num<<" :("<<endl;
      }
    }
    return 0;
}
