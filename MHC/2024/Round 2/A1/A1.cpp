/**
 *    author:  MaGnsi0
 *    created: 19.10.2024 20:01:55
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    vector<int64_t> peaks;
    for (int k = 0; 2 * k + 1 <= 18; ++k) {
        for (int start = 1; start + k <= 9; ++start) {
            string s = "";
            for (int j = 1; j <= k + 1; ++j) {
                s += char('0' + start + j - 1);
            }
            string t = s; t.pop_back();
            reverse(t.begin(), t.end());
            s += t;
            peaks.push_back(stoll(s));
        }
    }
    int T; cin >> T;
    for (int t = 1; t <= T; ++t) {
        cout << "Case #" << t << ": ";
        int64_t A, B, X;
        cin >> A >> B >> X;
        int ans = 0;
        for (int64_t x : peaks) {
            ans += A <= x && x <= B && x % X == 0;
        }
        cout << ans << "\n";
    }
}
