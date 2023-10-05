/**
 *    author:  MaGnsi0
 *    created: 05.05.2023 18:28:54
**/
#include <bits/stdc++.h>

using namespace std;

template <typename T>
struct segment_tree {
    int N;
    T E;
    vector<T> S;
    function<T(T, T)> F;
    segment_tree(int n, T e, function<T(T, T)> f) : N(n), E(e), S(2 * n, e), F(f) {}
    void update(int j, T x) {
        for (S[j += N] = x; j /= 2;) {
            S[j] = F(S[2 * j], S[2 * j + 1]);
        }
    }
    T query(int L, int R) {
        T l = E, r = E;
        for (L += N, R += N; L < R; L /= 2, R /= 2) {
            if (L % 2) {
                l = F(l, S[L++]);
            }
            if (R % 2) {
                r = F(S[--R], r);
            }
        }
        return F(l, r);
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        segment_tree<int> b(n + 1, n, [&](int i, int j) { return (a[i] >= a[j] ? i : j); });
        for (int i = 0; i < n; ++i) {
            b.update(i, i);
        }
        int ans = INT_MIN;
        for (int i = 0; i < n; ++i) {
            int j = -1;
            {
                int low = i + 1, high = n - 1;
                while (low <= high) {
                    int mid = (low + high) / 2;
                    if (a[b.query(i + 1, mid + 1)] >= a[i]) {
                        j = mid;
                        high = mid - 1;
                    } else {
                        low = mid + 1;
                    }
                }
            }
            int k = -1;
            if (j != -1) {
                int low = j + 1, high = n - 1;
                while (low <= high) {
                    int mid = (low + high) / 2;
                    if (a[b.query(j + 1, mid + 1)] >= min(a[i], a[j])) {
                        k = mid;
                        high = mid - 1;
                    } else {
                        low = mid + 1;
                    }
                }
            }
            if (k != -1) {
                ans = max(ans, a[i] + a[j] + a[k] - (k - i));
            }
        }
        for (int i = 0; i < n; ++i) {
            int j = -1;
            {
                int low = i + 1, high = n - 1;
                while (low <= high) {
                    int mid = (low + high) / 2;
                    if (a[b.query(i + 1, mid + 1)] >= a[i]) {
                        j = mid;
                        high = mid - 1;
                    } else {
                        low = mid + 1;
                    }
                }
            }
            int k = -1;
            {
                int low = 0, high = i - 1;
                while (low <= high) {
                    int mid = (low + high) / 2;
                    if (a[b.query(mid, i)] >= a[i]) {
                        k = mid;
                        low = mid + 1;
                    } else {
                        high = mid - 1;
                    }
                }
            }
            if (j != -1 && k != -1) {
                ans = max(ans, a[k] + a[i] + a[j] - (j - k));
            }
        }
        for (int i = 0; i < n; ++i) {
            int j = -1;
            {
                int low = i + 1, high = n - 1;
                while (low <= high) {
                    int mid = (low + high) / 2;
                    if (a[b.query(i + 1, mid + 1)] > a[i]) {
                        j = mid;
                        high = mid - 1;
                    } else {
                        low = mid + 1;
                    }
                }
            }
            int k = -1;
            if (j != -1) {
                int low = j + 1, high = n - 1;
                while (low <= high) {
                    int mid = (low + high) / 2;
                    if (a[b.query(j + 1, mid + 1)] > min(a[i], a[j])) {
                        k = mid;
                        high = mid - 1;
                    } else {
                        low = mid + 1;
                    }
                }
            }
            if (k != -1) {
                ans = max(ans, a[i] + a[j] + a[k] - (k - i));
            }
        }
        for (int i = 0; i < n; ++i) {
            int j = -1;
            {
                int low = i + 1, high = n - 1;
                while (low <= high) {
                    int mid = (low + high) / 2;
                    if (a[b.query(i + 1, mid + 1)] > a[i]) {
                        j = mid;
                        high = mid - 1;
                    } else {
                        low = mid + 1;
                    }
                }
            }
            int k = -1;
            {
                int low = 0, high = i - 1;
                while (low <= high) {
                    int mid = (low + high) / 2;
                    if (a[b.query(mid, i)] > a[i]) {
                        k = mid;
                        low = mid + 1;
                    } else {
                        high = mid - 1;
                    }
                }
            }
            if (j != -1 && k != -1) {
                ans = max(ans, a[k] + a[i] + a[j] - (j - k));
            }
        }
        for (int i = 0; i < n / 2; ++i) {
            swap(a[i], a[n - i - 1]);
        }
        b = segment_tree<int>(n + 1, n, [&](int i, int j) { return (a[i] >= a[j] ? i : j); });
        for (int i = 0; i < n; ++i) {
            b.update(i, i);
        }
        for (int i = 0; i < n; ++i) {
            int j = -1;
            {
                int low = i + 1, high = n - 1;
                while (low <= high) {
                    int mid = (low + high) / 2;
                    if (a[b.query(i + 1, mid + 1)] >= a[i]) {
                        j = mid;
                        high = mid - 1;
                    } else {
                        low = mid + 1;
                    }
                }
            }
            int k = -1;
            if (j != -1) {
                int low = j + 1, high = n - 1;
                while (low <= high) {
                    int mid = (low + high) / 2;
                    if (a[b.query(j + 1, mid + 1)] >= min(a[i], a[j])) {
                        k = mid;
                        high = mid - 1;
                    } else {
                        low = mid + 1;
                    }
                }
            }
            if (k != -1) {
                ans = max(ans, a[i] + a[j] + a[k] - (k - i));
            }
        }
        for (int i = 0; i < n; ++i) {
            int j = -1;
            {
                int low = i + 1, high = n - 1;
                while (low <= high) {
                    int mid = (low + high) / 2;
                    if (a[b.query(i + 1, mid + 1)] > a[i]) {
                        j = mid;
                        high = mid - 1;
                    } else {
                        low = mid + 1;
                    }
                }
            }
            int k = -1;
            if (j != -1) {
                int low = j + 1, high = n - 1;
                while (low <= high) {
                    int mid = (low + high) / 2;
                    if (a[b.query(j + 1, mid + 1)] > min(a[i], a[j])) {
                        k = mid;
                        high = mid - 1;
                    } else {
                        low = mid + 1;
                    }
                }
            }
            if (k != -1) {
                ans = max(ans, a[i] + a[j] + a[k] - (k - i));
            }
        }
        cout << ans << "\n";
    }
}
