/**
 *    author:  MaGnsi0
 *    created: 17.12.2021 16:55:50
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 2e6 + 6;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n), f(N, 0);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        f[a[i]]++;
    }
    vector<int> maxb(N, 0);
    for (int i = 1, cur = 0; i < N; ++i) {
        maxb[i] = cur;
        if (f[i]) {
            cur = i;
        }
    }
    sort(a.begin(), a.end());
    a.resize(unique(a.begin(), a.end()) - a.begin());
    int res = 0;
    for (int i = 0; i < (int)a.size(); ++i) {
        for (int j = 2 * a[i]; j < N; j += a[i]) {
            if (maxb[j] == 0) {
                continue;
            }
            res = max(res, maxb[j] % a[i]);
        }
    }
    cout << res;
}
