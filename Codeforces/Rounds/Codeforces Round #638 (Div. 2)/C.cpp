/**
 *    author:  MaGnsi0
 *    created: 25.10.2021 18:26:06
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        string s;
        cin >> n >> k >> s;
        sort(s.begin(), s.end());
        if (k == 1) {
            cout << s << "\n";
            continue;
        }
        if (s[0] != s[k - 1] || n == k) {
            cout << s[k - 1] << "\n";
            continue;
        }
        if (count(s.begin(), s.end(), s[0]) == n) {
            string t((n + k - 1) / k, s[0]);
            cout << t << "\n";
            continue;
        }
        if (s[k] != s[n - 1]) {
            cout << s.substr(k - 1, n - k + 1) << "\n";
        } else {
            cout << s[0];
            for (int i = 0; i < (n - 1) / k; ++i) {
                cout << s[k];
            }
            cout << "\n";
        }
    }
}

