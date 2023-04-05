/**
 *    author:  MaGnsi0
 *    created: 13.12.2022 14:37:00
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    int64_t ans = 0;
    string s;
    while (getline(cin, s)) {
        int n = (int)s.size();
        set<char> mp;
        for (int i = 0; i < n / 2; ++i) {
            mp.insert(s[i]);
        }
        for (int i = n / 2; i < n; ++i) {
            if (mp.count(s[i])) {
                if (islower(s[i])) {
                    ans += s[i] - 'a' + 1;
                } else {
                    ans += s[i] - 'A' + 1 + 26;
                }
                mp.erase(s[i]);
            }
        }
    }
    cout << ans;
}
