/**
 *    author:  MaGnsi0
 *    created: 12.05.2023 16:07:41
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
        vector<int> L(n), R(n), I(n);
        for (int i = 0; i < n; ++i) {
            cin >> L[i] >> R[i];
            I[i] = i;
        }
        if (n < k) {
            cout << 0 << "\n";
            for (int i = 0; i < n; ++i) {
                cout << 1;
                if (i != n - 1) { cout << " "; }
            }
            if (T) { cout << "\n"; }
            continue;
        }
        sort(I.begin(), I.end(), [&](int i, int j) {
                return make_pair(L[i], R[i]) < make_pair(L[j], R[j]);
            });
        vector<int> ans(n, 0);
        set<pair<int, int>> C;
        for (int i = 0; i < k; ++i) {
            C.insert(make_pair(-1, i));
        }
        for (int i = 0; i < n; ++i) {
            int j = I[i];
            int c = C.begin() -> second;
            int r = C.begin() -> first;
            C.erase(C.begin());
            C.insert(make_pair(max(R[j], r), c));
            ans[j] = c;
        }
        vector<tuple<int, int, int>> a(2 * n);
        for (int i = 0, j = 0; i < 2 * n; ++j, i += 2) {
            a[i] = make_tuple(L[j], ans[j], 1);
            a[i + 1] = make_tuple(R[j], ans[j], -1);
        }
        sort(a.begin(), a.end());
        int ans_ = 0, cnt = 0;
        vector<int> sum(k, 0);
        for (int i = 0; i + 1 < 2 * n; ++i) {
            if (get<2>(a[i]) == 1) {
                if (sum[get<1>(a[i])] == 0) { cnt++; }
                sum[get<1>(a[i])]++;
            } else {
                sum[get<1>(a[i])]--;
                if (sum[get<1>(a[i])] == 0) { cnt--; }
            }
            if (cnt == k) {
                ans_ += get<0>(a[i + 1]) - get<0>(a[i]);
            }
        }
        cout << ans_ << "\n";
        for (int i = 0; i < n; ++i) {
            cout << ans[i] + 1;
            if (i != n - 1) { cout << " "; }
        }
        if (T) { cout << "\n"; }
    }
}
