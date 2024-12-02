/**
 *    author:  MaGnsi0
 *    created: 02.12.2024 17:19:04
**/
#include <bits/stdc++.h>

using namespace std;

const int OO = 1e9 + 2;

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

unordered_map<int, int> get_ids(vector<tuple<int, int, int>> a) {
    set<int> s;
    for (auto [l, r, _] : a) {
        s.insert(l);
        s.insert(r);
    }
    unordered_map<int, int> ids;
    for (int x : s) {
        ids[x] = (int)ids.size();
    }
    return ids;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<tuple<int, int, int>> a(n);
        for (int i = 0; i < n; ++i) {
            int l; cin >> l;
            int r; cin >> r; r++;
            a[i] = make_tuple(l, r, i);
        }
        sort(a.begin(), a.end(), [](tuple<int, int, int> x, tuple<int, int, int> y) {
            auto p1 = make_pair(get<0>(x), -get<1>(x));
            auto p2 = make_pair(get<0>(y), -get<1>(y));
            return p1 < p2;
        });
        unordered_map<int, int> id = get_ids(a);
        int m = (int)id.size();
        vector<int> ans(n, 0);
        vector<multiset<int>> ls(m), rs(m);
        for (int i = 0; i < m; ++i) {
            ls[i].insert(0);
            rs[i].insert(OO);
        }
        segment_tree<int> maxl(m, 0, [](int x, int y) { return max(x, y); });
        segment_tree<int> minr(m, OO, [](int x, int y) { return min(x, y); });
        map<int, array<vector<tuple<int, int, int, int>>, 2>> event;
        for (auto [l, r, j] : a) {
            event[l][0].emplace_back(l, r, j, id[r]);
            event[r][1].emplace_back(l, r, j, id[r]);
        }
        for (auto [x, e] : event) {
            for (auto [l, r, j, k] : e[1]) {
                ls[k].erase(ls[k].find(l));
                rs[k].erase(rs[k].find(r));
                minr.update(k, *rs[k].begin());
                maxl.update(k, *ls[k].rbegin());
            }
            for (auto [l, r, j, k] : e[0]) {
                int L = maxl.query(k, m);
                int R = minr.query(k, m);
                if (L > R || L == 0 || R == OO) {
                    ans[j] = 0;
                } else {
                    ans[j] = R - L - (r - l);
                }
                ls[k].insert(l);
                rs[k].insert(r);
                minr.update(k, *rs[k].begin());
                maxl.update(k, *ls[k].rbegin());
            }
        }
        for (int i = 0; i < n; ++i) {
            if (i && get<0>(a[i - 1]) == get<0>(a[i]) && get<1>(a[i - 1]) == get<1>(a[i])) {
                ans[get<2>(a[i - 1])] = ans[get<2>(a[i - 1])] = 0;
            }
        }
        for (int i = 0; i < n; ++i) {
            cout << ans[i] << "\n";
        }
    }
}
