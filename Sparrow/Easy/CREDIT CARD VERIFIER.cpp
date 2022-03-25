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
    int n; cin >> n; cin.ignore(); 
    for (int i = 0; i < n; i++) {
        int ans=0;
        string card; getline(cin, card);
        card.erase(remove(card.begin(), card.end(), ' '), card.end());
        cerr<<card<<el;
        for ( int j = 0; j <= 15; j++ ) {
            int tmp =  2 * ( card[j] - '0' );
            if (j%2==0)  ans += (tmp > 9 ) ? tmp - 9 : tmp;  
            else   ans += card[j] - '0';         
        }
        cout << ((ans % 10 == 0) ? "YES" : "NO" ) << endl;
    }
    return 0;
}
