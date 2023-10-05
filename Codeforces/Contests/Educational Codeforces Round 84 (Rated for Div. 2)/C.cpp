/**
 *    author:  MaGnsi0
 *    created: 18.11.2021 15:52:44
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> x(k), y(k);
    for (int i = 0; i < k; ++i) {
        cin >> x[i] >> y[i];
    }
    vector<int> fx(k), fy(k);
    for (int i = 0; i < k; ++i) {
        cin >> fx[i] >> fy[i];
    }
    int l = 0, u = 0;
    string s = "";
    for (int i = 0; i < k; ++i) {
        l = max(l, y[i] - 1);
        u = max(u, x[i] - 1);
    }
    for (int i = 0; i < l; ++i) {
        s += "L";
    }
    for (int i = 0; i < u; ++i) {
        s += "U";
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j < m; ++j) {
            s += (i & 1 ? "R" : "L");
        }
        if (i < n) {
            s += "D";
        }
    }
    //assert((int)s.size() <= 2 * n * m);
    cout << (int)s.size() << "\n" << s;
}
