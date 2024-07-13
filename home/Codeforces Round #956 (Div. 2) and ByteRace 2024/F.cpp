/**
 *    author:  MaGnsi0
 *    created: 13.07.2024 19:00:40
**/
#include <bits/stdc++.h>

using namespace std;

const int OO = 1e7;

struct node {
    int min_i;
    array<int, 2> c;
    node() {
        min_i = OO;
        c[0] = c[1] = -1;
    }
    node(int i) {
        min_i = i;
        c[0] = c[1] = -1;
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int64_t k; cin >> k;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        vector<node> trie;
        function<void()> init_trie = [&]() {
            trie = vector<node>(1, node());
        };
        function<void(int)> insert = [&](int i) {
            int root = 0;
            for (int b = 31; b >= 0; --b) {
                int b1 = a[i] >> b & 1;
                if (trie[root].c[b1] == -1) {
                    trie[root].c[b1] = (int)trie.size();
                    trie.push_back(node(i));
                }
                trie[root].min_i = min(trie[root].min_i, i);
                root = trie[root].c[b1];
            }
            trie[root].min_i = min(trie[root].min_i, i);
        };
        function<int(int, int)> query = [&](int i, int x) {
            int root = 0, j = OO;
            for (int b = 31; b >= 0; --b) {
                int b1 = a[i] >> b & 1;
                int b2 = x >> b & 1;
                if (b2 == 0) {
                    if (trie[root].c[b1] == -1) { return j; }
                    root = trie[root].c[b1];
                } else {
                    if (trie[root].c[b1] != -1) {
                        int i = trie[root].c[b1];
                        j = min(j, trie[i].min_i);
                    }
                    if (trie[root].c[b1 ^ 1] == -1) { return j; }
                    root = trie[root].c[b1 ^ 1];
                }
            }
            j = min(j, trie[root].min_i);
            return j;
        };
        function<bool(int64_t)> F = [&](int64_t x) {
            init_trie();
            vector<int> best(n, -1);
            for (int i = n - 1; i >= 0; --i) {
                int j = query(i, x);
                if (j != OO) {
                    best[j] = max(best[j], i);
                }
                insert(i);
            }
            for (int i = 1; i < n; ++i) {
                best[i] = max(best[i], best[i - 1]);
            }
            int64_t good = 0;
            for (int i = 0; i < n; ++i) {
                good += best[i] + 1;
            }
            return good >= k;
        };
        int64_t low = 0, high = (1LL << 32), ans;
        while (low <= high) {
            int64_t mid = (low + high) / 2;
            if (F(mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        cout << ans << "\n";
    }
}
