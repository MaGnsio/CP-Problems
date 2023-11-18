/**
 *    author:  MaGnsi0
 *    created: 07.11.2023 20:55:21
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 1e6;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int d; cin >> d;
    int w; cin >> w;
    vector<int> a(n), b(n), c(n);
    iota(c.begin(), c.end(), 0);
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
    }
    sort(c.begin(), c.end(), [&](int i, int j) {
            return a[i] < a[j];
        });
    vector<int> T(4 * N), L(4 * N);
    function<void(int)> push = [&](int j) {
        T[2 * j + 1] += L[j];
        L[2 * j + 1] += L[j];
        T[2 * j + 2] += L[j];
        L[2 * j + 2] += L[j];
        L[j] = 0;
    };
    function<void(int, int, int, int, int, int)> update = [&](int j, int low, int high, int from, int to, int val) {
        if (low > high) { return; }
        if (high < from || to < low) { return; }
        if (from <= low && high <= to) {
            T[j] += val;
            L[j] += val;
            if (low != high) { push(j); }
        } else {
            push(j);
            int mid = (low + high) / 2;
            update(2 * j + 1, low, mid, from, to, val);
            update(2 * j + 2, mid + 1, high, from, to, val);
            T[j] = max(T[2 * j + 1], T[2 * j + 2]);
        }
    };
    function<int(int, int, int, int, int)> query = [&](int j, int low, int high, int from, int to) {
        if (low > high) { return 0; }
        if (high < from || to < low) { return 0; }
        if (from <= low && high <= to) { return T[j]; }
        push(j);
        int mid = (low + high) / 2;
        return max(query(2 * j + 1, low, mid, from, to), query(2 * j + 2, mid + 1, high, from, to));
    };
    int ans = 0;
    for (int i = 0, j = 0; i < n; ++i) {
        while (a[c[i]] - a[c[j]] >= d) {
            int from = max(b[c[j]] - w + 1, 0);
            int to = b[c[j]];
            update(0, 0, N - 1, from, to, -1);
            j++;
        }
        int from = max(b[c[i]] - w + 1, 0);
        int to = b[c[i]];
        update(0, 0, N - 1, from, to, +1);
        ans = max(ans, query(0, 0, N - 1, 0, N - 1));
    }
    cout << ans;
}
