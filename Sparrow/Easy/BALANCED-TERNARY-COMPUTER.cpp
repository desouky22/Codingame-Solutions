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
    ll n ; cin>>n; bool neg= (  n < 0 ? 1  :0 );
    n = abs(n);
    ll base[]= {0,1,-1};
    string Sp = "01T", Sn = "0T1",res="";
    do {
        ll rem = n%3 ;
         n -= base[rem];
         cerr<<rem<<el;
         if (neg) res = Sn[rem]+res;
         else res = Sp[rem]+res;
         n/=3;
         cerr<<n<<el;
        }while (n>0);
    cout<<res;
    return 0;
}


