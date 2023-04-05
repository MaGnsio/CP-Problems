/**
 *    author:  MaGnsi0
 *    created: 06.11.2022 16:46:45
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        string a, b;
        cin >> n >> a >> b;
        bool xored = true;
        for (int i = 0; i < n; ++i) {
            xored &= a[i] != b[i];
        }
        if (!xored && a != b) {
            cout << "NO\n";
            continue;
        }
        if (xored && count(a.begin(), a.end(), '0') == n) {
            cout << "YES\n";
            cout << 3 << "\n";
            cout << 1 << " " << n << "\n";
            cout << 1 << " " << 1 << "\n";
            cout << 2 << " " << n << "\n";
            continue;
        }
        if (xored && count(a.begin(), a.end(), '1') == n) {
            cout << "YES\n";
            cout << 1 << "\n";
            cout << 1 << " " << n << "\n";
            continue;
        }
        if (a == b && count(a.begin(), a.end(), '0') == n) {
            cout << "YES\n";
            cout << 0 << "\n";
            continue;
        }
        if (a == b && count(a.begin(), a.end(), '1') == n) {
            cout << "YES\n";
            cout << 2 << "\n";
            cout << 1 << " " << 1 << "\n";
            cout << 2 << " " << n << "\n";
            continue;
        }
        vector<int> p(n + 1, 0);
        vector<pair<int, int>> ans;
        for (int i = 0; i < n; ++i) {
            if (a[i] == '0') {
                continue;
            }
            ans.emplace_back(i + 1, i + 1);
            p[0]++, p[i]--, p[i + 1]++, p[n]--;
        }
        for (int i = 1; i <= n; ++i) {
            p[i] += p[i - 1];
        }
        for (int i = 0; i < n; ++i) {
            b[i] = (p[i] & 1 ? (b[i] == '1' ? '0' : '1') : b[i]);
        }
        if (count(b.begin(), b.end(), '0') != n && count(b.begin(), b.end(), '1') != n) {
            cout << "NO\n";
            continue;
        }
        if (count(b.begin(), b.end(), '1') == n) {
            ans.emplace_back(1, n);
            ans.emplace_back(1, 1);
            ans.emplace_back(2, n);
        }
        cout << "YES\n";
        cout << (int)ans.size() << "\n";
        for (int i = 0; i < (int)ans.size(); ++i) {
            cout << ans[i].first << " " << ans[i].second << "\n";
        }
    }
}
