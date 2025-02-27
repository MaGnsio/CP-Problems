/**
 *    author:  MaGnsi0
 *    created: 27.02.2025 17:58:15
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 3e6, O = 1e6;

template <typename T>
struct segment_tree {
    int N;
    T E;
    vector<T> S;
    function<T(T, T)> F;
    segment_tree(int n, T e, function<T(T, T)> f) : N(n), E(e), S(2 * n, e), F(f) {}
    void update(int j, T x) {
        for (S[j += N] += x; j /= 2;) {
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

int64_t F1(string s) {
    int n = (int)s.size();
    int64_t res = 0;
    vector<int64_t> pre(n);
    for (int i = 0; i < n; ++i) {
        pre[i] = (s[i] == '1' ? 3 : -1);
    }
    for (int i = 1; i < n; ++i) {
        pre[i] += pre[i - 1];
    }
    map<int, int64_t> mp; mp[0] = 1;
    for (int i = 0; i < n; ++i) {
        res += mp[pre[i] - 1]; mp[pre[i]]++;
    }
    return res;
}

int64_t F2(string s) {
    int n = (int)s.size();
    vector<int64_t> pre(n);
    for (int i = 0; i < n; ++i) {
        pre[i] = (s[i] == '1' ? -3 : 1);
    }
    for (int i = 1; i < n; ++i) {
        pre[i] += pre[i - 1];
    }
    segment_tree<int64_t> S(N, 0, [&](int64_t x, int64_t y) {
        return x + y;
    });
    S.update(O, 1);
    int64_t res = 0;
    for (int i = 0; i < n; ++i) {
        res += S.query(0, pre[i] - 1 + O);
        S.update(pre[i] + O, 1);
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    string s; cin >> s;
    int64_t ans = F1(s) + F2(s);
    cout << ans << "\n";
}
