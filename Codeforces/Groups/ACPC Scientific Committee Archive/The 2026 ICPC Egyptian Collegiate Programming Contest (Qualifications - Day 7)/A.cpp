/**
 *    author:  MaGnsi0
 *    created: 19.08.2026 20:05:26
**/
#include <bits/stdc++.h>

using namespace std;

const int B = 31;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int ans = 0;
        vector<array<int, 2>> trie(1, {-1, -1});
        function<void(int)> insert = [&](int x) {
            for (int b = 0, j = 0; b < B; ++b) {
                int v = (x >> b) & 1;
                if (trie[j][v ^ 1] != -1) {
                    ans = max(ans, 1 << b);
                }
                if (trie[j][v] == -1) {
                    trie[j][v] = (int)trie.size();
                    trie.push_back({-1, -1});
                }
                j = trie[j][v];
            }
        };
        while (n--) { int x; cin >> x; insert(x); }
        cout << ans << "\n";
    }
}
