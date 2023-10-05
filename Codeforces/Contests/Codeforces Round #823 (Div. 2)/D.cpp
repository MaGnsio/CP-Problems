/**
 *    author:  MaGnsi0
 *    created: 25.09.2022 16:34:11
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
        string s, t;
        cin >> s >> t;
        for (int i = 0; i < n; ++i) {
            if (t[i] < s[n - i - 1]) { swap(t[i], s[n - i - 1]); }
        }
        map<pair<char, char>, int> mp;
        for (int i = 0; i < n; ++i) {
            mp[make_pair(s[i], t[n - i - 1])]++;
        }
        int parity = 0;
        bool same = true;
        for (auto& [_, x] : mp) {
            parity += x % 2;
            same &= (x % 2 == 0 || _.first == _.second);
        }
        cout << (parity <= 1 && same ? "YES" : "NO") << "\n";
    }
}
