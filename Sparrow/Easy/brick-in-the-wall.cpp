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
    int x , n ; cin>>x>>n;
    double  res = 0; int weights[n];
    for (int i = 0; i < n; i++) cin>>weights[i];
    sort(weights,weights+n,greater<int>());
    for (int i = 0; i < n; i++) res +=  (i/x) * weights[i];
    printf("%.3f\n", 0.65*res);
    return 0;
}
