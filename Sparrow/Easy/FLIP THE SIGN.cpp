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
    int   H , W , sign = 0 ; string  str;
    cin >> H >> W; cin.ignore();
    int grid[H][W];
    for (int i = 0; i < H ; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> grid[i][j];
        }
    }
    char signGrid[H][W];
    for (int i = 0; i < H ; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> signGrid[i][j]; 
        }
    }
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (signGrid[i][j] == 'X' )
            {
                if ( sign == 0 || sign * grid[i][j] < 0 ) { sign = grid[i][j]; }
                else { cout << "false"; return 0; }
            }
        }
    }
    
    cout << "true" << endl;
    return 0;
}
