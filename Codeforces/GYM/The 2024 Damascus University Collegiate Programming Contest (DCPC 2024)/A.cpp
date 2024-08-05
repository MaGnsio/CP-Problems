/**
 *    author:  MaGnsi0
 *    created: 11.07.2024 22:34:39
**/
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<vector<int>> pos(n + 1);
    for (int i = 0; i < n; ++i) {
        pos[a[i]].push_back(i);
    }
    int low = 0, high = n;
    for (int i = 0; i <= n; ++i) {
        if (pos[i].empty()) {
            low = i;
            break;
        }
    }
    for (int i = low + 1; i <= n; ++i) {
        if (pos[i].empty()) {
            high = i;
            break;
        }
    }
    int missing = low, ans = low;
    function<bool(int)> F = [&](int mex) {
        int l = 0, r = 0;
        for (int i = 0; i < missing; ++i) {
            r = max(r, pos[i][0]);
        }
        vector<int> f(mex, 0), have(mex, 0);
        for (int i = r + 1; i < n; ++i) {
            if (a[i] < mex) { f[a[i]]++; }
        }
        for (int i = 0; i <= r; ++i) {
            if (a[i] < mex) { have[a[i]]++; }
        }
        int bad = 0;
        for (int i = 0; i < mex; ++i) {
            if (i == missing) { continue; }
            bad += f[i] == 0;
        }
        while (r < n) {
            if (bad == 0) { return true; }
            if (a[l] < mex) {
                bad -= f[a[l]] == 0;
                f[a[l]]++, have[a[l]]--;
                if (a[l] < missing) {
                    while (have[a[l]] == 0) {
                        r++;
                        if (r == n) { break; }
                        if (a[r] < mex) {
                            f[a[r]]--, have[a[r]]++;
                            bad += f[a[r]] == 0;
                        }
                    }
                }
            }
            l++; r = max(l, r);
        }
        return false;
    };
    while (low <= high) {
        int mid = (low + high) / 2;
        if (F(mid)) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    cout << ans << "\n";
}
