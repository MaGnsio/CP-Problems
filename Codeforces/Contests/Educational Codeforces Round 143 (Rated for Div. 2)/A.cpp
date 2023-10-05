/**
 *    author:  MaGnsi0
 *    created: 24.02.2023 21:04:39
**/
#include <bits/stdc++.h>

using namespace std;

int F(string s) {
    if (s.empty()) { return false; }
    int cnt = 0;
    for (int i = 1; i < (int)s.size(); ++i) {
        cnt += s[i] == s[i - 1];
    }
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        string s, t;
        cin >> s >> t;
        reverse(t.begin(), t.end());
        s += t;
        cout << (F(s) <= 1 ? "YES" : "NO") << "\n";
    }
}
