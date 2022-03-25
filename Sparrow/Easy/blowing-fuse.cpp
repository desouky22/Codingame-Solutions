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
    ll n ,m,c; cin>>n>>m>>c; ll con[n]; ll seq[m];
    for (int i = 0; i < n; ++i) {
        cin>>con[i];
    }
    ll mx=0 , pw = 0 ;
    for (int i = 0; i < m; ++i) {
        cin>>seq[i];
        pw +=  con[seq[i]-1];
        cerr<<con[seq[i]-1]<<endl;
        con[seq[i]-1] *=-1;
        mx = max(pw,mx);
    }
  //  cout<<mx<<endl;
  if (mx>c) {
      cout<<"Fuse was blown."<<endl;
  }
  else {
      cout<<"Fuse was not blown."<<endl;
      cout<<"Maximal consumed current was "<<mx<<" A."<<endl;
  }
    return 0;
}
