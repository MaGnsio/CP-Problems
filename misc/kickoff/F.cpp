/**
 *    author:  MaGnsi0
 *    created: 06.05.2023 18:00:33
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
    if (count(a.begin(), a.end(), 0) == n) {
        cout << -1;
        return 0;
    }
    vector<int> b(1, -1);
    for (int i = 0; i < n; ++i) {
        if (a[i] == 1) { b.push_back(i); }
    }
    b.push_back(n);
    int ans = 1;
    for (int j = 0; j + 2 < (int)b.size(); ++j) {
        ans = max(ans, b[j + 2] - b[j] - 1);
    }
    cout << ans;
}
