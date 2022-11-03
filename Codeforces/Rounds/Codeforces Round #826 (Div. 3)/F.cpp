/**
 *    author:  MaGnsi0
 *    created: 11.10.2022 18:08:35
**/
#include <bits/stdc++.h>

using namespace std;

const int OO = 2e9;

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
        vector<int> L(n), R(n), C(n);
        for (int i = 0; i < n; ++i) {
            cin >> L[i] >> R[i] >> C[i];
        }
        set<int> Points;
        for (int i = 0; i < n; ++i) {
            Points.insert(L[i]);
            Points.insert(R[i]);
        }
        int p = 0;
        map<int, int> X;
        for (auto& x : Points) {
            X[x] = p++;
        }
        map<int, multiset<int>> mpL, mpR;
        for (int i = 0; i < n; ++i) {
            mpL[L[i]].insert(R[i]);
            mpR[R[i]].insert(L[i]);
        }
        vector<vector<tuple<int, int, int>>> mpC(n);
        for (int i = 0; i < n; ++i) {
            mpC[C[i] - 1].push_back(make_tuple(L[i], R[i], i));
        }
        for (auto& [l, _] : mpL) {
            mpL[l].insert(-1);
        }
        for (auto& [r, _] : mpR) {
            mpR[r].insert(OO);
        }
        int m = p;
        segment_tree<int> stL(m, -1, [](int x, int y) { return max(x, y); });
        segment_tree<int> stR(m, OO, [](int x, int y) { return min(x, y); });
        for (auto& [l, _] : mpL) {
            stL.update(X[l], *_.rbegin());
        }
        for (auto& [r, _] : mpR) {
            stR.update(X[r], *_.begin());
        }
        vector<int> ans(n);
        for (int i = 0; i < n; ++i) {
            vector<tuple<int, int, int>> a = mpC[i];
            for (auto& [l, r, j] : a) {
                mpL[l].erase(mpL[l].find(r));
                mpR[r].erase(mpR[r].find(l));
                stL.update(X[l], *mpL[l].rbegin());
                stR.update(X[r], *mpR[r].begin());
            }
            for (auto& [l, r, j] : a) {
                int x = (mpL[r].size() <= 1 ? stL.query(0, X[r]) : *mpL[r].rbegin());
                int y = stR.query(X[l], m);
                if (x == -1) {
                    ans[j] = max(0, y - r);
                } else if (y == OO) {
                    ans[j] = max(0, l - x);
                } else {
                    ans[j] = min(max(0, l - x), max(0, y - r));
                }
            }
            for (auto& [l, r, j] : a) {
                mpL[l].insert(r);
                mpR[r].insert(l);
                stL.update(X[l], *mpL[l].rbegin());
                stR.update(X[r], *mpR[r].begin());
            }
        }
        for (int i = 0; i < n; ++i) {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
}
