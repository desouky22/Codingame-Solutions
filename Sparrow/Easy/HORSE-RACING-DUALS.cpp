#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define popCount(x) __builtin_popcountll(x)
using namespace __gnu_pbds;

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int main()
{
    int n;
    cin >> n; 
    int a[n]; 
    for (int i = 0; i < n; i++) {
        int pi; cin>>pi; 
       a[i]= pi ; 
    }
    sort(a,a+n); 
    int d = abs(a[0]-a[1]); 
    for(int i = 1 ; i < n -1 ; i ++ )  {
        d = min( d , abs(a[i] - a[i+1]) );  
    }
    cout<<d<<endl; 
}
