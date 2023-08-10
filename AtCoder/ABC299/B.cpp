/**
 *    author:  MaGnsi0
 *    created: 22.04.2023 14:05:07
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, x;
    cin >> n >> x;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    if (count(a.begin(), a.end(), x) == 0) {
        x = a[0];
    }
    int ans = -1;
    for (int i = 0; i < n; ++i) {
        if (a[i] != x) { continue; }
        if (ans == -1 || b[i] > b[ans]) {
            ans = i;
        }
    }
    cout << ans + 1;
}
