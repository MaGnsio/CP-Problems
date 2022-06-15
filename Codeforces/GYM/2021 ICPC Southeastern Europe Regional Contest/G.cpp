/**
 *    author:  MaGnsi0
 *    created: 25.03.2022 16:34:34
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<pair<int, int>> a(2 * n);
    for (int i = 0; i < 2 * n; ++i) {
        cin >> a[i].first >> a[i].second;
        if (a[i].first > a[i].second) {
            swap(a[i].first, a[i].second);
        }
    }
    sort(a.begin(), a.end(), [](pair<int, int> x, pair<int, int> y) {
            return (x.first + x.second < y.first + y.second);
       });
    long long ans = 0;
    for (int i = 0; i < 2 * n; ++i) {
        ans += 1LL * (i < n ? -a[i].first : a[i].second);
    }
    cout << ans;
}
