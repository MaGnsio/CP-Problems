/**
 *    author:  MaGnsi0
 *    created: 04.03.2023 19:36:11
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<string> a(2 * n - 2);
        for (int i = 0; i < 2 * n - 2; ++i) {
            cin >> a[i];
        }
        sort(a.begin(), a.end(), [](string s, string t) {
                return s.size() > t.size();
            });
        if (a[0].substr(1) != a[1].substr(0, a[1].size() - 1)) {
            swap(a[0], a[1]);
        }
        string ans = a[0];
        ans += a[1].back();
        bool ok = true;
        for (int i = 0; i < n / 2; ++i) {
            ok &= ans[i] == ans[n - i - 1];
        }
        cout << (ok ? "YES" : "NO") << "\n";
    }
}
