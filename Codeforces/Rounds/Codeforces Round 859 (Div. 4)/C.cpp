/**
 *    author:  MaGnsi0
 *    created: 20.03.2023 02:08:52
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        string s;
        cin >> n >> s;
        bool ok = true;
        vector<int> a(26, -1);
        for (int i = 0; i < n; ++i) {
            if (a[s[i] - 'a'] == -1) {
                a[s[i] - 'a'] = i % 2;
            } else {
                ok &= a[s[i] - 'a'] == i % 2;
            }
        }
        cout << (ok ? "YES" : "NO") << "\n";
    }
}
