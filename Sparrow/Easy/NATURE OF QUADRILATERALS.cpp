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
double distance(int x1,  int x2,int y1, int y2)
{
    return sqrt(pow(x2 - x1, 2) +
                pow(y2 - y1, 2) * 1.0);
}
int main() {
    Peow_peow
    int n;
    cin >> n; cin.ignore();
    while (n--) {
        string a;
        int x_a;
        int y_a;
        string b;
        int x_b;
        int y_b;
        string c;
        int x_c;
        int y_c;
        string d;
        int x_d;
        int y_d;
            cin >> a >> x_a >> y_a >> b >> x_b >> y_b >> c >> x_c >> y_c >> d >> x_d >> y_d;
            cin.ignore();
        double ab = distance(x_a, x_b, y_a, y_b);
        double bc = distance(x_b, x_c, y_b, y_c);
        double cd = distance(x_c, x_d, y_c, y_d);
        double da = distance(x_d, x_a, y_d, y_a);
        double ac = distance(x_c, x_a, y_c, y_a);
        double bd = distance(x_b, x_d, y_b, y_d);
        bool parll = 0, rhm = 0, rec = 0, square = 0;
        if (ab == cd && bc == da) parll = 1;
        if (ab == bc && cd == da) rhm = 1;
        if (ac == bd) rec = 1;
        cout << a << b << c << d << " is a ";
        if (rec && rhm)cout << "square.";
        else if (rec && (!rhm)) cout << "rectangle.";
        else if ((!rec) && rhm)cout << "rhombus.";
        else if (parll) cout << "parallelogram.";
        else cout << "quadrilateral.";
        cout<<endl;
    }
    return 0;
}
