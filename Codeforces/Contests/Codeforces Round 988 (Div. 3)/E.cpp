/**
 *    author:  MaGnsi0
 *    created: 18.11.2024 16:58:10
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int i = 1; i < n; ++i) {
            cout << "? " << 1 << " " << i + 1 << endl;
            cin >> a[i];
        }
        if (a[n - 1] == 0) {
            cout << "! IMPOSSIBLE" << endl;
            continue;
        }
        string s = "";
        for (int i = 0; i < n; ++i) {
            if (a[i]) {
                int o = i - a[i], z = a[i]; 
                while (o--) { s += "1"; }
                while (z--) { s += "0"; }
                s += "1";
                break;
            }
        }
        for (int i = (int)s.size(); i < n; ++i) {
            s += (a[i] == a[i - 1] ? "0" : "1");
        }
        cout << "! " << s << endl;
    }
}
