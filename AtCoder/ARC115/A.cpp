/**
 *    author:  MaGnsi0
 *    created: 09.11.2022 20:16:54
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<int64_t> b(2, 0);
    for (int i = 0; i < n; ++i) {
        b[count(a[i].begin(), a[i].end(), '1') % 2]++;
    }
    cout << b[0] * b[1];
}
