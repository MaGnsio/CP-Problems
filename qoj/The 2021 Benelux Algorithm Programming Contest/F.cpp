/**
 *    author:  MaGnsi0
 *    created: 05.10.2023 16:24:34
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first >> a[i].second;
    }
    if (n & 1) {
        cout << "impossible";
        return 0;
    }
    sort(a.begin(), a.end());
    int x = a[0].first + a[n - 1].first;
    int y = a[0].second + a[n - 1].second;
    for (int i = 0; i < n / 2; ++i) {
        if (a[i].first + a[n - i - 1].first != x) {
            cout << "impossible";
            return 0;
        }
        if (a[i].second + a[n - i - 1].second != y) {
            cout << "impossible";
            return 0;
        }
    }
    cout << "possible";
}
