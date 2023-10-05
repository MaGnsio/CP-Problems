/**
 *    author:  MaGnsi0
 *    created: 23.05.2022 22:29:19
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t OO = 1e11;

struct node {
    int64_t d11, d12, d21, d22;
};

template <typename T>
struct segment_tree {
    int N;
    T E;
    vector<T> ST;
    function<T(T, T)> F;
    void update(int pos, T val) {
        for (ST[pos += N] = val; pos /= 2;) {
            ST[pos] = F(ST[2 * pos], ST[2 * pos + 1]);
        }
    }
    T query(int L, int R) {
        T l = E, r = E;
        for (L += N, R += N; L < R; L /= 2, R /= 2) {
            if (L % 2) {
                l = F(l, ST[L++]);
            }
            if (R % 2) {
                r = F(ST[--R], r);
            }
        }
        return F(l, r);
    }
    segment_tree(int n, function<T(T, T)> f, T e) : N(n), E(e), ST(2 * n, e), F(f) {}
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<int> d1x(n - 1), d1y(n - 1), d2x(n - 1), d2y(n - 1);
    for (int i = 0; i < n - 1; ++i) {
        cin >> d1x[i] >> d1y[i] >> d2x[i] >> d2y[i];
        d1x[i]--, d1y[i]--, d2x[i]--, d2y[i]--;
    }
    function<node(node, node)> f = [](node a, node b) {
        node ans;
        ans.d11 = min(a.d11 + b.d11, a.d12 + b.d21); 
        ans.d12 = min(a.d11 + b.d12, a.d12 + b.d22);
        ans.d21 = min(a.d21 + b.d11, a.d22 + b.d21);
        ans.d22 = min(a.d21 + b.d12, a.d22 + b.d22);
        return ans;
    };
    node E;
    E.d11 = E.d22 = 0;
    E.d12 = E.d21 = OO;
    segment_tree<node> st(n - 2, f, E);
    for (int i = 0; i < n - 2; ++i) {
        node a;
        a.d11 = abs(d1x[i] + 1 - d1x[i + 1]) + abs(d1y[i] - d1y[i + 1]) + 1;
        a.d12 = abs(d1x[i] + 1 - d2x[i + 1]) + abs(d1y[i] - d2y[i + 1]) + 1;
        a.d21 = abs(d2x[i] - d1x[i + 1]) + abs(d2y[i] + 1 - d1y[i + 1]) + 1;
        a.d22 = abs(d2x[i] - d2x[i + 1]) + abs(d2y[i] + 1 - d2y[i + 1]) + 1;
        st.update(i, a);
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1--, y1--, x2--, y2--;
        int l1 = max(x1, y1), l2 = max(x2, y2);
        if (l1 == l2) {
            cout << abs(x1 - x2) + abs(y1 - y2) << "\n";
            continue;
        }
        if (l1 > l2) {
            swap(x1, x2);
            swap(y1, y2);
            swap(l1, l2);
        }
        if (l2 == l1 + 1) {
            int64_t ans = OO;
            ans = min(ans, int64_t(abs(x1 - d1x[l1]) + abs(y1 - d1y[l1]) + 1 + abs(d1x[l1] + 1 - x2) + abs(d1y[l1] - y2)));
            ans = min(ans, int64_t(abs(x1 - d2x[l1]) + abs(y1 - d2y[l1]) + 1 + abs(d2x[l1] - x2) + abs(d2y[l1] + 1 - y2)));
            cout << ans << "\n";
            continue;
        }
        int64_t ans = OO;
        node X = st.query(l1, l2 - 1);
        ans = min(ans, abs(x1 - d1x[l1]) + abs(y1 - d1y[l1]) + 1 + X.d11 + abs(d1x[l2 - 1] + 1 - x2) + abs(d1y[l2 - 1] - y2));
        ans = min(ans, abs(x1 - d1x[l1]) + abs(y1 - d1y[l1]) + 1 + X.d12 + abs(d2x[l2 - 1] - x2) + abs(d2y[l2 - 1] + 1 - y2));
        ans = min(ans, abs(x1 - d2x[l1]) + abs(y1 - d2y[l1]) + 1 + X.d21 + abs(d1x[l2 - 1] + 1 - x2) + abs(d1y[l2 - 1] - y2));
        ans = min(ans, abs(x1 - d2x[l1]) + abs(y1 - d2y[l1]) + 1 + X.d22 + abs(d2x[l2 - 1] - x2) + abs(d2y[l2 - 1] + 1 - y2));
        cout << ans << "\n";
    }
}
