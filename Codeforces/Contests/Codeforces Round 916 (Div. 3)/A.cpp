/**
 *    author:  MaGnsi0
 *    created: 21.12.2023 15:16:00
**/
#include <bits/stdc++.h>

using namespace std;

const int M = 26;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        string s; cin >> s;
        vector<int> F(M);
        for (char c : s) {
            F[c - 'A']++;
        }
        int ans = 0;
        for (int i = 0; i < M; ++i) {
            ans += F[i] >= i + 1;
        }
        cout << ans << "\n";
    }
}
