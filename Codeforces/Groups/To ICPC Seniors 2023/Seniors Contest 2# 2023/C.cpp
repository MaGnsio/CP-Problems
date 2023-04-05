/**
 *    author:  MaGnsi0
 *    created: 05.02.2023 09:32:54
**/
#include <bits/stdc++.h>

using namespace std;

int64_t P10[19];

int64_t lower_bound(int64_t x, int64_t y) {
    int64_t z = x;
    vector<int> d;
    while (z) {
        d.push_back(z % 10);
        z /= 10;
    }
    reverse(d.begin(),d.end());
    int64_t ans = -1;
    for (int i = 0; i < (int)d.size(); ++i) {
        x -= d[i] * P10[d.size() - 1];
        x *= 10;
        x += d[i];
        if (x <= y) {
            if (ans == -1 || ans < x) {
                ans = x;
            }
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    P10[0] = 1;
    for (int i = 1; i < 20; ++i) {
        P10[i] = P10[i - 1] * 10;
    }
    int n;
    cin >> n;
    vector<int64_t> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    a[0] = lower_bound(a[0], 1e18);
    for (int i = 1; i < n; ++i) {
        int64_t nx = lower_bound(a[i], a[i - 1]);
        if (nx == -1) {
            cout << "NO";
            return 0;
        }
        a[i] = nx;
    }
    cout << "YES";
}
