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
ll next (ll n ) {
    long s = n;
    while (s > 0) {
        n = n + (s % 10);
        s = s / 10;
    }
    return n;
}
int main() {
    Peow_peow
   ll r ; cin>>r; bool chk = 0 ;
    for (ll st = r-1; st > 0; --st)
    {
        ll cur = st;
        cur = next(cur);
        if (cur == r) {
            chk = true;
            break;
        }
    }
    if (chk) cout<<"YES"<<el;
    else cout<<"NO"<<el;
    return 0;
}


