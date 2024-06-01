/**
 *    author:  MaGnsi0
 *    created: 01.06.2024 15:00:23
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, l, r;
    cin >> n >> l >> r;
    vector<int> a(n);
    iota(a.begin(), a.end(), 1);
    reverse(a.begin() + l - 1, a.begin() + r);
    for (int i = 0; i < n; ++i) {
        cout << a[i] << " ";
    }
}
