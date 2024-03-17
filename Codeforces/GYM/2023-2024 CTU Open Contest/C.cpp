/**
 *    author:  MaGnsi0
 *    created: 25.01.2024 20:32:38
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int m; cin >> m;
    int k; cin >> k;
    vector<int> a(n), b(n), c(m, k);
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
        a[i]--, b[i]--;
    }
    int X = 0, Y = 0;
    for (int i = 0; i < n; ++i) {
        if (c[a[i]]) {
            X++, c[a[i]]--;
        } else if (c[b[i]]) {
            Y++, c[b[i]]--;
        }
    }
    cout << X << " " << Y;
}
