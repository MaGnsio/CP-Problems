/**
 *    author:  MaGnsi0
 *    created: 05/10/2021 23:24:04
**/
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int n, max_x = 0;
    cin >> n;
    vector<int> f(N, 0);
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        max_x = max(max_x, x);
        f[x]++;
    }
    for (int i = 0; i < N; ++i) {
        if (i == max_x) {
            break;
        }
        f[i + 1] += (f[i] / 2);
        f[i] -= (2 * (f[i] / 2));
    }
    int cnt = 0;
    for (int i = 0; i < N; ++i) {
        if (i == max_x) {
            break;
        }
        cnt += f[i];
    }
    if (cnt > 1) {
        cout << "N";
    } else if (cnt == 0) {
        int x = f[max_x], lg = log(x);
        int a = (1 << lg), b = x - a;
        if ((x > 1) && ((a & (a - 1)) == 0) && (b == 0 || ((b & (b - 1)) == 0))) {
            cout << "Y";
        } else {
            cout << "N";
        }
    } else {
        int x = f[max_x];
        if ((x & (x - 1)) == 0) {
            cout << "Y";
        } else {
            cout << "N";
        }
    }
}
