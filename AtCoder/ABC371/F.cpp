/**
 *    author:  MaGnsi0
 *    created: 14.09.2024 16:05:44
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5, I = -4 * N;

int64_t n, T[4 * N], L[4 * N];

int64_t sum(int64_t x, int64_t y) {
    if (x > y) { return 0; }
    if (x < 0 && y < 0) {
        return -sum(-y, -x);
    }
    if (x < 0) {
        return sum(0, y) - sum(0, -x);
    }
    int64_t L = x * (x - 1) / 2;
    int64_t R = y * (y + 1) / 2;
    assert(R >= 0);
    return R - L;
}

void push(int j, int low, int high) {
    if (L[j] == I) { return; }
    if (low == high) { L[j] = I; return; }
    int mid = (low + high) / 2;
    T[2 * j + 1] = sum(L[j], L[j] + (mid - low + 1) - 1);
    T[2 * j + 2] = sum(L[j] + (mid - low + 1), L[j] + (mid - low + 1) + (high - (mid + 1) + 1) - 1);
    L[2 * j + 1] = L[j];
    L[2 * j + 2] = L[j] + (mid - low + 1);
    L[j] = I;
}

void setp(int pos, int64_t val, int j = 0, int low = 0, int high = N - 1) {
    if (low > high) { return; }
    if (pos < low || pos > high) { return; }
    if (low == high) {
        assert(low == pos);
        T[j] = val;
        return;
    }
    int mid = (low + high) / 2;
    setp(pos, val, 2 * j + 1, low, mid);
    setp(pos, val, 2 * j + 2, mid + 1, high);
    T[j] = T[2 * j + 1] + T[2 * j + 2];
}

void update(int from, int to, int64_t start, int j = 0, int low = 0, int high = N - 1) {
    if (low > high) { return; }
    if (to < low || high < from) { return; }
    if (from <= low && high <= to) {
        T[j] = sum(start, start + (high - low + 1) - 1);
        L[j] = start; push(j, low, high);
        return;
    }
    push(j, low, high);
    int mid = (low + high) / 2;
    int C = max(min(mid, to) - max(low, from) + 1, 0);
    update(from, to, start, 2 * j + 1, low, mid);
    update(from, to, start + C, 2 * j + 2, mid + 1, high);
    T[j] = T[2 * j + 1] + T[2 * j + 2];
}

int64_t query(int from, int to, int j = 0, int low = 0, int high = N - 1) {
    if (low > high) { return 0; }
    if (to < low || high < from) { return 0; }
    if (from <= low && high <= to) { return T[j]; }
    push(j, low, high);
    int mid = (low + high) / 2;
    return query(from, to, 2 * j + 1, low, mid) + query(from, to, 2 * j + 2, mid + 1, high);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    for (int i = 0; i < 4 * N; ++i) {
        T[i] = 0, L[i] = I;
    }
    int n; cin >> n;
    for (int i = 0; i < n; ++i) {
        int64_t val; cin >> val;
        setp(i, val);
    }
    function<int(int64_t, int)> lower_boundp = [&](int64_t val, int i) {
        if (i == 0) { return 0; }
        if (query(i - 1, i - 1) < val) { return i; }
        int low = 0, high = i - 1, k = -1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (query(mid, mid) - mid < val - i + 1) {
                k = mid; low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return k + 1;
    };
    function<int(int64_t, int)> nupper_boundp = [&](int64_t val, int i) {
        if (i == n - 1) { return n - 1; }
        if (query(i + 1, i + 1) > val) { return i; }
        int low = i + 1, high = n - 1, k = n;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (query(mid, mid) - mid > val - i - 1) {
                k = mid; high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return k - 1;
    };
    int64_t ans = 0;
    int Q; cin >> Q;
    while (Q--) {
        int j; cin >> j; j--;
        int64_t val; cin >> val;
        int posj = query(j, j);
        if (posj == val) { continue; }
        if (posj < val) {
            int i = nupper_boundp(val, j);
            int64_t C = i - j + 1; 
            ans += sum(val, val + C - 1) - query(j, i);
            update(j, i, val);
        } else {
            int i = lower_boundp(val, j);
            int64_t C = j - i + 1; 
            ans += query(i, j) - sum(val - C + 1, val);
            update(i, j, val - C + 1);
        }
    }
    cout << ans << "\n";
}
