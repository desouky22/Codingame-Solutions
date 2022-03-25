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
int valid(const char c1, const char c2) {
    return ( (c1 == '{' && c2 == '}') || (c1 == '[' && c2 == ']') || (c1 == '(' && c2 == ')') );
}
int main() {

    Peow_peow
        string str; cin >> str;
        cerr<<str<<el; stack<char> st;
        bool ans = false;
        if (str[0] == '}' || str[0] == ')' || str[0] == ']') {
            cout<<"false"<<el;
            return 0;
        }
        for (int i = 0; i < str.size(); ++i) {
            if (str[i] == '{' || str[i] == '(' || str[i] == '[') { st.push(str[i]); }
            else if (str[i] == '}' || str[i] == ')' || str[i] == ']') {
                if (st.empty() || !valid(st.top(), str[i])) break;
                st.pop();
            }
        }
        if (st.empty()) ans= true;
    
        cout<<(ans?"true" : "false")<<el;
    return 0;
}
