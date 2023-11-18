/**
 *    author:  MaGnsi0
 *    created: 03.11.2023 17:04:07
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t MOD = 11092019;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s; cin >> s;
    vector<int64_t> F(26, 1);
    for (char c : s) {
        F[c - 'a']++;
    }
    int64_t ans = 1;
    for (int i = 0; i < 26; ++i) {
        ans *= F[i];
        ans %= MOD;
    }
    cout << ans;
}
