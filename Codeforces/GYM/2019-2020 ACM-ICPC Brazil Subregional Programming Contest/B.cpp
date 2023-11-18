/**
 *    author:  MaGnsi0
 *    created: 31.10.2023 20:35:17
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    bool win = true;
    for (int i = 1; i < n; ++i) {
        win = win && a[i] <= a[0];
    }
    cout << (win ? 'S' : 'N');
}
