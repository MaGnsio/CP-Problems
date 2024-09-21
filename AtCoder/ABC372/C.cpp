/**
 *    author:  MaGnsi0
 *    created: 21.09.2024 15:09:38
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int Q; cin >> Q;
    string s; cin >> s;
    int ans = 0;
    for (int i = 0; i + 2 < n; ++i) {
        ans += s.substr(i, 3) == "ABC";
    }
    function<int(int)> val = [&](int j) {
        int res = 0;
        if (j - 2 >= 0) {
            res += s.substr(j - 2, 3) == "ABC";
        }
        if (j - 1 >= 0 && j + 1 < n) {
            res += s.substr(j - 1, 3) == "ABC";
        }
        if (j >= 0 && j + 2 < n) {
            res += s.substr(j, 3) == "ABC";
        }
        return res;
    };
    while (Q--) {
        int j; cin >> j; j--;
        char c; cin >> c;
        ans -= val(j);
        s[j] = c;
        ans += val(j);
        cout << ans << "\n";
    }
}
