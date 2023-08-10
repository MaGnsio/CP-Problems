/**
 *    author:  MaGnsi0
 *    created: 27.05.2023 16:23:35
**/
#include <bits/stdc++.h>

using namespace std;

__int128 sum(__int128 L, __int128 R) {
    __int128 y = R * (R + 1) / 2;
    __int128 x = L * (L - 1) / 2;
    return max(__int128(0), y - x);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int64_t n, h;
    cin >> n >> h;
    vector<int64_t> t(n + 2), d(n + 2), I(n + 2);
    for (int i = 1; i <= n; ++i) {
        cin >> t[i] >> d[i];
    }
    t[0] = 0, t[n + 1] = h + 1;
    iota(I.begin(), I.end(), 0);
    sort(I.begin(), I.end(), [&](int64_t i, int64_t j) {
            return t[i] < t[j];
        });
    vector<int64_t> s(n + 2);
    s[n + 1] = d[I[n + 1]];
    for (int i = n; i >= 0; --i) {
        s[i] = max(s[i + 1], d[I[i]]);
    }
    function<bool(int64_t)> F = [&](int64_t x) {
        __int128 best = 0, damage = 0;
        for (int i = 0, k; i < n + 1; /*_*/) {
            int64_t L = t[I[i]], R = L;
            if (L > x) { break; }
            for (int j = i; j < n + 2; ++j) {
                if (t[I[i]] != t[I[j]]) {
                    R = t[I[j]] - 1;
                    k = j;
                    break;
                }
                best = max(best, __int128(t[I[j]]) * d[I[j]]);
            }
            R = min(R, x);
            int64_t low = L, high = R, sep = L - 1;
            while (low <= high) {
                int64_t mid = low + (high - low) / 2;
                if (best > __int128(mid) * s[k]) {
                    sep = mid;
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
            __int128 add = best * (sep - L + 1);
            add = min(add, __int128(h));
            add += s[k] * sum(max(sep + 1, int64_t(1)), R);
            add = min(add, __int128(h));
            damage += add;
            i = k;
        }
        return damage >= __int128(h);
    };
    int64_t low = 1, high = h, ans = h;
    while (low <= high) {
        int64_t mid = low + (high - low) / 2;
        if (F(mid)) {
            ans = mid, high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    cout << ans;
}
