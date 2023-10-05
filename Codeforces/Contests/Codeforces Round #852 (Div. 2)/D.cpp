/**
 *    author:  MaGnsi0
 *    created: 14.02.2023 17:28:59
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    vector<int> pos_a(n + 1), pos_b(n + 1);
    for (int i = 0; i < n; ++i) {
        pos_a[a[i]] = i;
        pos_b[b[i]] = i;
    }
    vector<int> min_a(n + 1, n), min_b(n + 1, n);
    for (int i = 1; i <= n; ++i) {
        min_a[i] = min(min_a[i - 1], pos_a[i]);
        min_b[i] = min(min_b[i - 1], pos_b[i]);
    }
    vector<int> max_a(n + 1, -1), max_b(n + 1, -1);
    for (int i = 1; i <= n; ++i) {
        max_a[i] = max(max_a[i - 1], pos_a[i]);
        max_b[i] = max(max_b[i - 1], pos_b[i]);
    }
    int64_t ans = 1;
    for (int mex = 1; mex <= n; ++mex) {
        int64_t x = pos_a[mex], L_a = min_a[mex - 1], R_a = max_a[mex - 1];
        int64_t y = pos_b[mex], L_b = min_b[mex - 1], R_b = max_b[mex - 1];
        int64_t L = min(L_a, L_b);
        int64_t R = max(R_a, R_b);
        if (L < x && x < R) { continue; }
        if (L < y && y < R) { continue; }
        int64_t A = -1;
        if (x <= L) { A = max(A, x); }
        if (y <= L) { A = max(A, y); }
        int64_t B = n;
        if (x >= R) { B = min(B, x); }
        if (y >= R) { B = min(B, y); }
        if (L > R) {
            vector<int64_t> I = {-1, x, y, n}; 
            sort(I.begin(), I.end());
            for (int j = 1; j < 4; ++j) {
                ans += (I[j] - I[j - 1]) * (I[j] - I[j - 1] - 1) / 2;
            }
        } else {
            ans += int64_t(L - A) * (B - R);
        }
    }
    cout << ans;
}
