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
struct horse {
    int v, e;
};
int diff( const struct horse* h1, const struct horse* h2) {
    if (h1==h2) return 10e9; 
    else return  abs(h2->v - h1->v) + abs(h2->e - h1->e) ; 
}
int main() {
    Peow_peow
    int N; cin>>N; 
    int  min_d = 10e9;
    struct horse h[N], *it = h;
    for (int i = 0; i < N; i++) {
        cin>>it->v>>it->e;
        it++;
    }
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            if (diff(&h[i], &h[j]) < min_d) { 
                min_d = diff(&h[i], &h[j]); 
            }
        }
    cout<<min_d<<el;
    return 0;
}
