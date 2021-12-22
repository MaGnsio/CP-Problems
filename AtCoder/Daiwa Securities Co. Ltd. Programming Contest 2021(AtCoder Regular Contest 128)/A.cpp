/**
 *    author:  MaGnsi0
 *    created: 15.11.2021 20:04:36
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<int> res(n, 0);
    for (int i = 0; i < n - 1; ++i) {
        if (a[i] > a[i + 1]) {
            res[i] ^= 1;
            res[i + 1] ^= 1;
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << res[i] << " ";
    }
}
