/**
 *    author:  MaGnsi0
 *    created: 23.11.2022 16:58:33
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        int64_t comps = n, ans = 0;
        vector<int> p(n), s(n, 1);
        iota(p.begin(), p.end(), 0);
        function<int(int)> find = [&](int x) {
            if (p[x] != x) {
                p[x] = find(p[x]);
            }
            return p[x];
        };
        function<void(int, int, int64_t)> unite = [&](int x, int y, int64_t cost) {
            x = find(x), y = find(y);
            if (x == y) {
                return;
            }
            if (s[x] < s[y]) {
                swap(x, y);
            }
            p[y] = x;
            s[x] += s[y];
            ans += cost;
            comps--;
        };
        for (int j = 0; j < 30; ++j) {
            vector<int> tp;
            for (int i = 0; i < n; ++i) {
                if ((a[i] >> j) & 1) {
                    tp.push_back(find(i));
                }
            }
            sort(tp.begin(), tp.end());
            tp.resize(unique(tp.begin(), tp.end()) - tp.begin());
            for (int i = 1; i < (int)tp.size(); ++i) {
                unite(tp[0], tp[i], 1 << j);
            }
        }
        cout << (comps == 1 ? ans : -1) << "\n";
    }
}
