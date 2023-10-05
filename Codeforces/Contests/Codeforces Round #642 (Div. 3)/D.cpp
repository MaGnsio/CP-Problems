/**
 *    author:  MaGnsi0
 *    created: 05/10/2021 12:50:18
**/
#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;

struct comp {
    bool operator()(pii const& x, pii const& y) {
        return ((x.second - x.first < y.second - y.first)
             || (x.second - x.first == y.second - y.first && x.first > y.first));
    }
};

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int T;
    cin >> T;
    while (T--) {
        int n, cur_i = 1;
        cin >> n;
        vector<int> a(n + 1, 0);
        priority_queue<pii, vector<pii>, comp> q;
        q.push({1, n});
        while (!q.empty()) {
            int l = q.top().first, r = q.top().second;
            q.pop();
            if (l == r) {
                a[l] = cur_i++;
                continue;
            }
            int m;
            if ((r - l + 1) & 1) {
                m = (l + r) / 2;
            } else {
                m = (l + r - 1) / 2;
            }
            int nl_1 = l, nr_1 = m - 1;
            int nl_2 = m + 1, nr_2 = r;
            if (nl_1 <= nr_1) {
                q.push({nl_1, nr_1});
            }
            if (nl_2 <= nr_2) {
                q.push({nl_2, nr_2});
            }
            a[m] = cur_i++;
        }
        for (int i = 1; i <= n; ++i) {
            cout << a[i] << " ";
        }
        cout << "\n";
    }
}
