/**
 *    author:  MaGnsi0
 *    created: 18.11.2023 14:01:08
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
    sort(a.rbegin(), a.rend());
    for (int i = 0; i < n; ++i) {
        if (a[i] != a[0]) {
            cout << a[i];
            return 0;
        }
    }
}
