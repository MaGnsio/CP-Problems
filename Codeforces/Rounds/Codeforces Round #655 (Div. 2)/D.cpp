/**
 *    author:  MaGnsi0
 *    created: 22.12.2021 17:00:28
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<long long> b;
    for (int i = 0; i < n; i += 2) {
        b.push_back(a[i]);
    }
    for (int i = 1; i < n; i += 2) {
        b.push_back(a[i]);
    }
    b.insert(b.end(), b.begin(), b.end());
    long long cur = accumulate(b.begin(), b.begin() + (n + 1) / 2, 0LL), res = cur;
    for (int i = (n + 1) / 2; i < (int)b.size(); ++i) {
        cur -= b[i - (n + 1) / 2];
        cur += b[i];
        res = max(res, cur);
    }
    cout << res;
}
