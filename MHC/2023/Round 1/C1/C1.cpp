/**
 *    author:  MaGnsi0
 *    created: 07.10.2023 20:26:45
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("C1.in", "r", stdin);
    freopen("C1.out", "w", stdout);
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        int n; cin >> n;
        string s; cin >> s;
        vector<int> F(n + 1);
        int Q; cin >> Q;
        while (Q--) { int x; cin >> x; F[x]++; }
        for (int i = n; i; --i) {
            for (int j = 2 * i; j <= n; j += i) {
                F[j] += F[i];
            }
        }
        for (int i = 1; i <= n; ++i) {
            if (F[i] % 2 == 0) { continue; }
            s[i - 1] = (s[i - 1] == '1' ? '0' : '1');
        }
        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            if (s[i - 1] == '0') { continue; }
            for (int j = i; j <= n; j += i) {
                s[j - 1] = (s[j - 1] == '1' ? '0' : '1');
            }
            ans++;
        }
        cout << "Case #" << t << ": " << ans << "\n";
    }
}
