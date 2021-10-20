/**
 *    author:  MaGnsi0
 *    created: 17/07/2021 13:36:28
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    string x, y;
    cin >> x >> y;
    if (x.size() < y.size()) {
        cout << -1;
        return 0;
    }
    string t = "";
    sort(y.begin(), y.end());
    for (int i = 0; i <= x.size() - y.size(); ++i) {
        string k = x.substr(i, y.size());
        string o = k;
        sort(k.begin(), k.end());
        if (k == y) {
            if (t.empty() || o > t) {
                t = o;
            }
        }
    }
    if (t.empty()) {
        cout << -1;
    } else {
        cout << t;
    }
}
