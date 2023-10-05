/**
 *    author:  MaGnsi0
 *    created: 03.02.2023 17:32:42
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
        vector<int> fp(n), fs(n);
        fp[0] = (1 << (s[0] - 'a'));
        for (int i = 1; i < n; ++i) {
            fp[i] = fp[i - 1] | (1 << (s[i] - 'a'));
        }
        fs[n - 1] = (1 << (s[n - 1] - 'a'));
        for (int i = n - 2; i >= 0; --i) {
            fs[i] = fs[i + 1] | (1 << (s[i] - 'a'));
        }
        int ans = __builtin_popcount(fs[0]);
        for (int i = 0; i + 1 < n; ++i) {
            ans = max(ans, __builtin_popcount(fp[i]) + __builtin_popcount(fs[i + 1]));
        }
        cout << ans << "\n";
    }
}
