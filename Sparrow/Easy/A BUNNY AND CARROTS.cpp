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
    int m, n, t, col;
    cin >> m >> n >> t; cin.ignore();

    int cur =  2 * (m+n) ;
    vector<int> d(n + 2, 0);
    d[0] = d[n + 1] = m;

    while( cin >> col ) {
        ++d[col];
        cur += 2;
        if ( d[col - 1] >= d[col] ) cur -= 2;
        if ( d[col + 1] >= d[col] ) cur -= 2;
        if ( d[col] == m) cur -= 2;

        cout << cur << el;
    }
    return 0;
}
