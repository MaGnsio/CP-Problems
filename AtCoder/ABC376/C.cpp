/**
 *    author:  MaGnsi0
 *    created: 19.10.2024 15:15:57
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<int> a(n), b(n - 1);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < n - 1; ++i) {
        cin >> b[i];
    }
    sort(b.begin(), b.end());
    vector<bool> good(n + 1, false); good[n] = true;
    for (int i = n - 1; i > 0; --i) {
        good[i] = a[i] <= b[i - 1];
    }
    for (int i = n - 2; i >= 0; --i) {
        good[i] = good[i] && good[i + 1];
    }
    int x = -1;
    bool pgood = true;
    for (int i = 0; i < n; ++i) {
        if (good[i + 1] && pgood) {
            x = a[i];
            break;
        }
        pgood = pgood && a[i] <= b[i];
    }
    cout << x;
}
