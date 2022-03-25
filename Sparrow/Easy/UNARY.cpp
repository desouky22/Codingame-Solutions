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
string decimalToBinary(ll n)
{

    string s = bitset<64> (n).to_string();


    const auto loc1 = s.find('1');

    if(loc1 != string::npos)
        return s.substr(loc1);

    return "0";
}
int main() {
    Peow_peow
    string message;  getline(cin, message);
    string ans="";
    for (int i = 0; i < message.size(); ++i) {
        int tt = (int)(message[i]);
        string tmp = decimalToBinary(tt);
        while  (tmp.size() < 7 ) {tmp ="0"+tmp; }
        ans+=tmp;
    }
    cerr<<ans<<el;
     int i = 0;
    char currentChar;
    while (i < ans.size() )
    {
        if (ans[i] == '0')
        {
            cout<<"00 ";
            currentChar = '0';
        }
        else
        {
            cout<<"0 ";
            currentChar = '1';
        }

        while (ans[i] == currentChar)
        {
            cout<<"0";
            i++;
            if(i ==ans.size())
                break;
        }

        if (i < ans.length())
            cout<<" ";
    }

    return 0;
}
