/**
 *    author:  MaGnsi0
 *    created: 25.07.2024 16:05:28
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 2e6 + 10, O = 1e6;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<int> X1(n), Y1(n), X2(n), Y2(n);
    for (int i = 0; i < n; ++i) {
        cin >> X1[i] >> Y1[i] >> X2[i] >> Y2[i];
        X1[i] += O, Y1[i] += O, X2[i] += O, Y2[i] += O;
    }
    vector<tuple<int, int, int, int>> segments;
    for (int i = 0; i < n; ++i) {
        segments.emplace_back(X1[i], 1, Y1[i], Y2[i]);
        segments.emplace_back(X2[i] + 1, 0, Y1[i], Y2[i]);
    }
    sort(segments.begin(), segments.end());
    vector<int> T(4 * N), L(4 * N);
    function<void(int, int, int)> push = [&](int j, int l, int r) {
        if (l == r) { return; }
        T[2 * j + 1] += L[j];
        T[2 * j + 2] += L[j];
        L[2 * j + 1] += L[j];
        L[2 * j + 2] += L[j];
        L[j] = 0;
        return;
    };
    function<void(int, int, int, int, int, int)> add_ = [&](int j, int low, int high, int from, int to, int val) {
        if (low > high) { return; }
        if (high < from || to < low) { return; }
        if (from <= low && high <= to) {
            T[j] += val;
            L[j] += val;
            push(j, low, high);
            return;
        }
        push(j, low, high);
        int mid = (low + high) / 2;
        add_(2 * j + 1, low, mid, from, to, val);
        add_(2 * j + 2, mid + 1, high, from, to, val);
        T[j] = max(T[2 * j + 1], T[2 * j + 2]);
    };
    function<int(int, int, int, int, int)> get_ = [&](int j, int low, int high, int from, int to) {
        if (low > high) { return 0; }
        if (high < from || to < low) { return 0; }
        if (from <= low && high <= to) { return T[j]; }
        push(j, low, high);
        int mid = (low + high) / 2;
        return max(get_(2 * j + 1, low, mid, from, to), get_(2 * j + 2, mid + 1, high, from, to));
    };
    function<void(int, int, int)> add = [&](int from, int to, int val) {
        add_(0, 0, N - 1, from, to, val);
    };
    function<int(int, int)> get = [&](int from, int to) {
        return get_(0, 0, N - 1, from, to);
    };
    int ans = 1;
    for (auto [x, k, y1, y2] : segments) {
        add(y1, y2, (k ? 1 : -1));
        ans = max(ans, get(0, N - 1));
    }
    cout << ans;
}
