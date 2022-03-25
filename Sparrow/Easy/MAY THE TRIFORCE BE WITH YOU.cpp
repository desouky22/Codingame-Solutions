#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define popCount(x) __builtin_popcountll(x)
using namespace __gnu_pbds;
ll MOD = 1e9 + 7;
#define el '\n'
#define Peow_peow ios::sync_with_stdio(0), ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
int main() {
    Peow_peow
    int n; cin>>n ; char stars[500] = "*";
    for ( int i = 1; i <= n; i++ ) {
       if (i==1)cout<< ".";
       else cout<<" ";
        for (int j = 0; j < 2*n-1-i; j++) { cout<<" "; }
        cout<<stars<<el;
        strcat(stars, "**");
    }
    strcpy(stars, "*");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n-i; j++)   { cout<<" "; }
        cout<<stars;
        for (int j = 1; j <= n*2- strlen(stars); j++) { cout<<" "; }
        cout<<stars<<el;
        strcat(stars, "**");
    }

    return 0;
}
