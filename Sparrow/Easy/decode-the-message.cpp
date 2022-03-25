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
    ll   P; cin >> P;  cin.ignore();
    string C, ans=""; getline(std::cin, C);
    cerr<<C.size()<<el;
    while ( P >= 0 ) {
        ans += C[P % C.size() ];
        cerr<<ans<<el;
        P = P / C.size() - 1;
    }
    cout<<ans<<el;
    return 0;
}
