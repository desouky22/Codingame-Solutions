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
        int n;
        cin >> n; int cost = 0 ; priority_queue < int, vector<int> , greater<int> > pq ;
        for (int i = 0; i < n; i++) {
            int x ; cin>>x;
           pq.push(x);
        }

        while (pq.size() > 1 ){
            int mn = 0 ;
            mn+=pq.top(); pq.pop();
            mn+=pq.top(); pq.pop();
            pq.push(mn);
            cost+=mn;
        }
        cout<<cost<<el;
        return 0;
    }
