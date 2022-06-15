/**
 *    author:  MaGnsi0
 *    created: 10.04.2022 21:59:20
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int64_t> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int64_t sum = accumulate(a.begin(), a.end(), (int64_t)0);
    vector<int64_t> b(k);
    for (int i = 0; i < n; ++i) {
        b[i % k] += a[i];
    }
    cout << sum - *max_element(b.begin(), b.end());
}
