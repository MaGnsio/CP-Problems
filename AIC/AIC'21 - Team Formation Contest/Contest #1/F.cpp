/**
 *    author:  MaGnsi0
 *    created: 16/07/2021 13:24:43
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int n, cnt = 0;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        cnt += (v[i] == i);
    }
    if (cnt == n) {
        cout << cnt;
        return 0;
    }
    for (int i = 0; i < n; ++i) {
        if (v[i] == i) {
            continue;
        }
        if (v[v[i]] == i) {
            cout << cnt + 2;
            return 0;
        }
    }
    cout << cnt + 1;
}
