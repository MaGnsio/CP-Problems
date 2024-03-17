/**
 *    author:  MaGnsi0
 *    created: 10.02.2024 14:32:02
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, k, Q;
    cin >> n >> k >> Q;
    string s, ans;
    cin >> s >> ans;
    reverse(s.begin(), s.end());
    while (Q--) {
        string new_ans = "";
        for (int i = 0; i < n; ++i) {
            string bi = "";
            for (int j = i - k; j <= i + k; ++j) {
                bi += ans[(j + n) % n];
            }
            reverse(bi.begin(), bi.end());
            int x = 0;
            for (int j = 0; j < 2 * k + 1; ++j) {
                if (bi[j] == '1') { x |= (1 << j); }
            }
            new_ans += s[x];
        }
        ans = new_ans;
    }
    cout << ans;
}
