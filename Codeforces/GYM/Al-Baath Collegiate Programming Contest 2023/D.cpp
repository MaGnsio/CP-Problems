/**
 *    author:  MaGnsi0
 *    created: 07.07.2023 02:48:58
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        vector<int> c(1, a[0]);
        for (int i = 1; i < n; ++i) {
            if (a[i] == c.back() && c.size() > 1 && c.back() == c[c.size() - 2]) {
                continue;
            }
            c.push_back(a[i]);
        }
        a = c; n = (int)c.size();
        vector<int> b(1, 0);
        for (int i = 0; i < 1024; ++i) {
            if (__builtin_popcount(i) == k) {
                b.push_back(i);
            }
        }
        int m = (int)b.size();
        vector<vector<int>> trie(1, vector<int>(2, -1));
        function<int(int)> ask = [&](int x) {
            int root = 0, ans = 0;
            for (int i = 9; i >= 0; --i) {
                int y = ((x >> i) & 1);
                if (trie[root][y ^ 1] != -1) {
                    ans |= (1 << i);
                    root = trie[root][y ^ 1];
                } else {
                    root = trie[root][y];
                }
            }
            return ans;
        };
        function<void(int)> add = [&](int x) {
            int root = 0;
            for (int i = 9; i >= 0; --i) {
                int y = ((x >> i) & 1);
                if (trie[root][y] == -1) {
                    trie[root][y] = (int)trie.size();
                    trie.push_back(vector<int>(2, -1));
                }
                root = trie[root][y];
            }
        };
        int ans = b[m - 1];
        vector<bool> added(1024, false);
        for (int i = 0; i < m; ++i) {
            add(b[i]); added[b[i]] = true;
        }
        for (int i = 0, p = 0; i < n; ++i) {
            p ^= a[i];
            ans = max(ans, ask(p));
            for (int j = 0; j < m; ++j) {
                if (added[p ^ b[j]]) { continue; }
                add(p ^ b[j]); added[p ^ b[j]] = true;
            }
            if (ans == 1023) { break; }
        }
        cout << ans << "\n";
    }
}
