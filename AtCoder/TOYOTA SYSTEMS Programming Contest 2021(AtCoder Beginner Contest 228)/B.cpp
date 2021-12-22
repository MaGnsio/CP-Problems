/**
 *    author:  MaGnsi0
 *    created: 20.11.2021 14:06:34
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, k;
    cin >> n >> k, k--;
    vector<int> a(n), v(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        a[i]--;
    }
    while (!v[k]) {
        v[k] = 1;
        k = a[k];
    }
    cout << accumulate(v.begin(), v.end(), 0);
}
