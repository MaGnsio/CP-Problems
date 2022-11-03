/**
 *    author:  MaGnsi0
 *    created: 05.03.2022 13:55:00
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        a[i]--;
    }
    int q, s = (int)sqrt(n) + 1;
    cin >> q;
    vector<tuple<int, int, int, int>> query(q);
    for (int i = 0; i < q; ++i) {
        int l, r;
        cin >> l >> r;
        query[i] = make_tuple(l / s, r, l - 1, i);
    }
    sort(query.begin(), query.end());
    vector<int> cnt(n, 0), ans(q);
    int L = 0, R = 0, P = 0;
    for (int i = 0; i < q; ++i) {
        int j = get<3>(query[i]);
        int l = get<2>(query[i]);
        int r = get<1>(query[i]);
        while (R < r) {
            if (cnt[a[R]] & 1) {
                P++;
            }
            cnt[a[R]]++;
            R++;
        }
        while (L > l) {
            L--;
            if (cnt[a[L]] & 1) {
                P++;
            }
            cnt[a[L]]++;
        }
        while (R > r) {
            R--;
            cnt[a[R]]--;
            if (cnt[a[R]] & 1) {
                P--;
            }
        }
        while (L < l) {
            cnt[a[L]]--;
            if (cnt[a[L]] & 1) {
                P--;
            }
            L++;
        }
        ans[j] = P;
    }
    for (int i = 0; i < q; ++i) {
        cout << ans[i] << "\n";
    }
}
