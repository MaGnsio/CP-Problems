/**
 *    author:  MaGnsi0
 *    created: 28.12.2022 17:44:31
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }
    vector<int> U, V, W, I;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            U.push_back(i);
            V.push_back(j);
            W.push_back(a[i][j]);
            I.push_back((int)I.size());
        }
    }
    sort(I.begin(), I.end(), [&](int i, int j) {
            return W[i] > W[j];
        });
    int ans = 0;
    vector<int> P(n), X, Y;
    iota(P.begin(), P.end(), 0);
    function<int(int)> find = [&](int x) {
        if (P[x] != x) {
            P[x] = find(P[x]);
        }
        return P[x];
    };
    function<void(int, int, int)> unite = [&](int x, int y, int w) {
        x = find(x), y = find(y);
        if (x == y) {
            return;
        }
        if (x > y) {
            swap(x, y);
        }
        ans += w;
        P[y] = x;
        X.push_back(x + 1);
        Y.push_back(y + 1);
    };
    for (int i = 0; i < (int)I.size(); ++i) {
        unite(U[I[i]], V[I[i]], W[I[i]]);
    }
    cout << ans << "\n";
    for (int i = 0; i < n - 1; ++i) {
        cout << X[i] << " " << Y[i] << "\n";
    }
}
