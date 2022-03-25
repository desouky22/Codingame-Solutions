#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int W; cin >> W; cin.ignore(); int H; cin >> H; cin.ignore();
    string str; getline(cin, str);
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    for (int i = 0; i < H; i++) {
        string row;
        getline(cin, row);
        string ans;
        for (char c : str) {
            int pos = (int) (c - 'a');
            if (pos < 0 || pos > 25) {
                pos = 26;
            }
            int st = pos * W;
            ans += row.substr(st, W);
        }
          cout << ans << endl;
    }
    return 0; 
}
