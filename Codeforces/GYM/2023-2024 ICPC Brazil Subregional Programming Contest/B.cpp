/**
 *    author:  MaGnsi0
 *    created: 14.09.2023 00:56:14
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //\/*_*\/
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        int j; cin >> j;
        a[j - 1] = i;
    }
    int ans = 1;
    for (int i = 1; i < n; ++i) {
        ans += a[i] < a[i - 1];
    }
    cout << ceil(log2(ans));
}
