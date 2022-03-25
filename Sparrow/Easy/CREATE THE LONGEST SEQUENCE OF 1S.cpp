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
int main() {
    Peow_peow
    string s ; cin>>s; 
    int mx= 0 ; int cur = 0 ;  int pre = 0 ; 
    for (int i = 0; i < s.size(); i++)
    {
       if(s[i] == '1' ) cur++ ; 
       else { 
          if  ( s[i+1] != '1' ) { 
              pre = 0 ; 
          }  
          else  pre = cur;
          cur= 0; 
       } 
       mx = max(pre + cur , mx) ; 
    }
    
    cout<<mx+1<<el;
     
    return 0;
}
// 10010101
