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

ll  solve(vector<int>& T, int num)
{
    vector<int> robber_time(num, 0);

    int opened = 0;
    for (int i = 0; i < num; ++i)
    {
        robber_time[i] += T[opened];
        opened++;
    }
    
    while (opened < T.size())
    {
        sort(robber_time.begin(), robber_time.end());

        robber_time[0] += T[opened];
        opened++;
    }

    ll total_time = *max_element(robber_time.begin(), robber_time.end());

    return total_time;
}

int main()
{
    int R;
    cin >> R; cin.ignore();
    int V;
    cin >> V; cin.ignore();
    
    vector<int> T(V, 0);
    
    for (int i = 0; i < V; ++i) 
    {
        int C;
        int N;
        cin >> C >> N; cin.ignore();
        T[i] += pow(10, N) * pow(5, C-N);
    }
    
    cout << solve(T, R) << "\n";
}

