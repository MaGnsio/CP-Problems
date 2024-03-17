/**
 *    author:  MaGnsi0
 *    created: 10.02.2024 14:44:52
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<tuple<long long, long long, long long>> b(n);
    for (int i = 0; i < n; ++i) {
        long long x; cin >> x;
        long long y; cin >> y;
        long long bad; cin >> bad;
        long long good; cin >> good;
        b[i] = make_tuple(x, y, bad - good);
    }
    sort(b.begin(), b.end(), [&](tuple<long long, long long, long long> x, tuple<long long, long long, long long> y) {
            long double ang1 = atan2l(get<1>(x), get<0>(x));
            long double ang2 = atan2l(get<1>(y), get<0>(y));
            return ang1 < ang2;
        });
    vector<long long> a; a.push_back(get<2>(b[0]));
    for (int i = 1; i < n; ++i) {
        long double ang1 = atan2l(get<1>(b[i]), get<0>(b[i]));
        long double ang2 = atan2l(get<1>(b[i - 1]), get<0>(b[i - 1]));
        if (ang1 == ang2) {
            a.back() += get<2>(b[i]);
        } else {
            a.push_back(get<2>(b[i]));
        }
    }
    n = (int)a.size();
    long long ans = 0, now = 0;
    for (int i = 0; i < n; ++i) {
        now += a[i];
        ans = max(ans, now);
        now = max(now, 0LL);
    }
    vector<long long> pre(n), suf(n);
    pre[0] = a[0];
    for (int i = 1; i < n; ++i) {
        pre[i] = pre[i - 1] + a[i];
    }
    suf[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; --i) {
        suf[i] = suf[i + 1] + a[i];
    }
    vector<long long> max_pre(n), max_suf(n);
    max_pre[0] = pre[0];
    for (int i = 1; i < n; ++i) {
        max_pre[i] = max(max_pre[i - 1], pre[i]);
    }
    max_suf[n - 1] = suf[n - 1];
    for (int i = n - 2; i >= 0; --i) {
        max_suf[i] = max(max_suf[i + 1], suf[i]);
    }
    for (int i = 0; i < n - 1; ++i) {
        ans = max(ans, max_pre[i] + max_suf[i + 1]);
    }
    cout << ans;
}
