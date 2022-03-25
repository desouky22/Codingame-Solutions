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
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
int main() {
    Peow_peow
    int    a ,n ; cin >> a >> n;
    vector<int> vis (n,-1), ans (n, 0);
    ans[0] = a;
    for (int i = 0; i < n-1 ; i++ )
    {
        if ( vis[ans[i]] >= 0 ) {
            ans[i+1] = i - vis[ans[i]];
        }
        vis[ ans[i] ] = i;
    }
    cout << ans[n-1] <<el;
    return 0;
}
