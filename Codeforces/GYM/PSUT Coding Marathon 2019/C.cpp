/**
 *    author:  MaGnsi0
 *    created: 21/09/2021 21:00:28
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    if (n <= 4) {
        cout << -1;
        return 0;
    }
    vector<int> a;
    for (int i = 0; i < n; ++i) {
        if (i & 1) {
            a.push_back(v[i]);
        }
    }
    for (int i = 0; i < n; ++i) {
        if (!(i & 1)) {
            a.push_back(v[i]);
        }
    }
    if (n % 2 == 0) {
        swap(a[n / 2], a[n / 2 + 1]);
    }
    for (int i = 0; i < n; ++i) {
        cout << a[i] << " ";
    }
}
