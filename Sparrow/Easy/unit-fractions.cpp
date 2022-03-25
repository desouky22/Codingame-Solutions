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
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
int main() {

    Peow_peow
    ll n, mxN; cin>>n; mxN = n*n;
    for( ll i = 1; i < mxN/2+1; i++ )
    {
        ll x = n+mxN/i, y = n+i;
        if ( x < y  ) break;
        if ( mxN % i == 0 ) {
            cout<<"1/"<<n<<" = "<<"1/"<<x<<" + "<<"1/"<<y<<endl;
        }
    }
    return 0;
}
