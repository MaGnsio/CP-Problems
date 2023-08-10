/**
 *    author:  MaGnsi0
 *    created: 25.02.2023 14:35:49
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
        a[i] %= 2;
    }
    if (n & 1) {
        cout << -1;
        return 0;
    }
    int x = count(a.begin(), a.end(), 0);
    cout << max(x, n - x) - n / 2;
}
