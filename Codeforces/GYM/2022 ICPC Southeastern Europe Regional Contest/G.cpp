/**
 *    author:  MaGnsi0
 *    created: 28.12.2022 17:10:52
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<int64_t> x(n), r(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> r[i];
    }
    vector<int64_t> a(n);
    for (int i = 1; i < n; ++i) {
        a[i] = x[i] - x[i - 1] - a[i - 1];
    }
    int64_t min_even = INT64_MAX, min_odd = INT64_MAX;
    for (int i = 0; i < n; ++i) {
        if (i & 1) {
            min_odd = min(min_odd, a[i]);
        } else {
            min_even = min(min_even, a[i]);
        }
    }
    function<void(int)> go = [&](int i) {
        vector<int64_t> ans(n);
        map<int64_t, int> mp;
        for (int i = 0; i < n; ++i) {
            mp[r[i]]++;
        }
        ans[i] = mp.begin() -> first;
        (mp.begin() -> second)--;
        for (int j = i - 1; j >= 0; --j) {
            int g = x[j + 1] - x[j] - ans[j + 1];
            if (mp[g] == 0) {
                return;
            }
            ans[j] = g;
            mp[g]--;
        }
        for (int j = i + 1; j < n; ++j) {
            int g = x[j] - x[j - 1] - ans[j - 1];
            if (mp[g] == 0) {
                return;
            }
            ans[j] = g;
            mp[g]--;
        }
        for (int i = 0; i < n; ++i) {
            cout << ans[i] << " ";
        }
        exit(0);
    };
    for (int i = 1; i < n; i += 2) {
        if (a[i] == min_odd) {
            go(i);
            break;
        }
    }
    for (int i = 0; i < n; i += 2) {
        if (a[i] == min_even) {
            go(i);
            break;
        }
    }
    assert(1 == 0);
}
