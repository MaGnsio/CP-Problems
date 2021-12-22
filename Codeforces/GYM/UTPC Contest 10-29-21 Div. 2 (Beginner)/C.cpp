/**
 *    author:  MaGnsi0
 *    created: 21.11.2021 15:37:43
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
    int res = 0;
    for (int i = 1; i < n; ++i) {
        res += abs(a[i] - a[i - 1]);
    }
    cout << res;
}
