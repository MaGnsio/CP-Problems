/**
 *    author:  MaGnsi0
 *    created: 25.11.2021 16:25:41
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        int n = s.size();
        if ((s[n - 1] - '0') % 2 == 0) {
            cout << "0";
        } else if ((s[0] - '0') % 2 == 0) {
            cout << "1";
        } else {
            bool ok = false;
            for (auto& c : s) {
                if ((c - '0') % 2 == 0) {
                    ok = true;
                }
            }
            cout << (ok ? "2" : "-1");
        }
        cout << "\n";
    }
}
