/**
 *    author:  MaGnsi0
 *    created: 13.07.2024 17:55:43
**/
#include <bits/stdc++.h>

using namespace std;

const int OO = 1e6;

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
    int n; cin >> n;
    string s; cin >> s;
    vector<set<int>> ocur(26, {OO});
    for (int i = 0; i < n; ++i) {
        ocur[s[i] - 'a'].insert(i);
    }
    vector<segment_tree<int>> a(26, segment_tree<int>(n, OO, [](int x, int y) { return min(x, y); }));
    for (int i = 0; i < n; ++i) {
        vector<int> p(26);
        for (int j = 0; j < 26; ++j) {
            p[j] = *ocur[j].lower_bound(i);
        }
        sort(p.begin(), p.end());
        for (int j = 0; j < 26; ++j) {
            a[j].update(i, p[j] - i + 1);
        }
    }
    int Q; cin >> Q;
    while (Q--) {
        int l; cin >> l; l--;
        int r; cin >> r; r--;
        int c = 0;
        for (int i = 0; i < 26; ++i) {
            c += *ocur[i].lower_bound(l) <= r;
        }
        int low = 1, high = r - l + 1, ans = high;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (a[c - 1].query(l, r - mid + 2) <= mid) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        cout << ans << "\n";
    }
}
