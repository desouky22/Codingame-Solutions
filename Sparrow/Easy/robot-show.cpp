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
    int    l, n, cur;
    cin >> l >> n; cin.ignore();
    vector<int> v(n);
    for (int i = 0; i < n; i++ ) { cin >> v[i]; }
     int mn = *min_element(v.begin(),v.end());
    int mx = *max_element(v.begin(),v.end());
    cout << max(l - mn, mx) << endl;
    return 0;
}
