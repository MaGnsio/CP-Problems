/**
 *    author:  MaGnsi0
 *    created: 22.12.2021 16:23:39
**/
#include <bits/stdc++.h>

using namespace std;

struct operation {
    int type;
    long long x0, x1;
    long long y0, y1;
    long long z0, z1;
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("input2.txt", "r", stdin);
    int type;
    vector<int> X, Y, Z;
    vector<operation> A;
    while (cin >> type) {
        operation a;
        a.type = type;
        cin >> a.x0 >> a.x1 >> a.y0 >> a.y1 >> a.z0 >> a.z1;
        a.x1++, a.y1++, a.z1++;
        A.push_back(a);
        X.push_back(a.x0);
        X.push_back(a.x1);
        Y.push_back(a.y0);
        Y.push_back(a.y1);
        Z.push_back(a.z0);
        Z.push_back(a.z1);
    }
    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());
    sort(Z.begin(), Z.end());
    int N = (int)X.size();
    vector<vector<vector<bool>>> g(N, vector<vector<bool>>(N, vector<bool>(N, false)));
    auto get = [&](vector<int>& B, int b) {
        return (int)(lower_bound(B.begin(), B.end(), b) - B.begin());
    };
    for (operation a : A) {
        int x0 = get(X, a.x0);
        int x1 = get(X, a.x1);
        int y0 = get(Y, a.y0);
        int y1 = get(Y, a.y1);
        int z0 = get(Z, a.z0);
        int z1 = get(Z, a.z1);
        for (int i = x0; i < x1; ++i) {
            for (int j = y0; j < y1; ++j) {
                for (int k = z0; k < z1; k++) {
                    g[i][j][k] = a.type;
                }
            }
        }
    }
    long long res = 0;
    for (int i = 0; i < N - 1; ++i) {
        for (int j = 0; j < N - 1; ++j) {
            for (int k = 0; k < N - 1; ++k) {
                res += 1LL * g[i][j][k] * (X[i + 1] - X[i]) * (Y[j + 1] - Y[j]) * (Z[k + 1] - Z[k]);
            }
        }
    }
    cout << res << "\n";
}
