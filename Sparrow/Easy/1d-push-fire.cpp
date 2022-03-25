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
    int  t; cin>>t;
    while ( t-- )
    {
        char line[256]; cin>>line;
        int ans = 0;
        for ( int j = 0; j < strlen(line); ++j )
        {
            if ( line[j] == 'f' ) { 
                ans++; 
                j+=2; 
            }
        }

        cout<<ans<<el;
    }
    return 0;
}
