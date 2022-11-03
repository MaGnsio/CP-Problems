/**
 *    author:  MaGnsi0
 *    created: 31.10.2022 19:10:46
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        char x;
        string s;
        cin >> n >> x >> s;
        if (x == 'g') {
            cout << 0 << "\n";
            continue;
        }
        s += s;
        vector<int> a, b;
        for (int i = 0; i < 2 * n; ++i) {
            if (s[i] == 'g') {
                a.push_back(i);
            }
            if (s[i] == x) {
                b.push_back(i);
            }
        }
        int ans = 0;
        for (int i = 0; i < (int)b.size(); ++i) {
            auto it = lower_bound(a.begin(), a.end(), b[i]);
            if (it == a.end()) {
                break;
            }
            ans = max(ans, *it - b[i]);
        }
        cout << ans << "\n";
    }
}
