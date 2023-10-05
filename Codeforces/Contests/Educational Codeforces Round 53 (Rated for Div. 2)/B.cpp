/**
 *    author:  MaGnsi0
 *    created: 31/08/2021 01:54:44
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int n;
    cin >> n;
    vector<int> v(n), k(n, 1);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        v[i]--;
    }
    int cur = 0;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        x--;
        if (!k[x]) {
            cout << 0 << " ";
            continue;
        }
        int cnt = 0;
        while (v[cur] != x) {
            k[v[cur]] = 0;
            cnt++;
            cur++;
        }
        k[x] = 0;
        cnt++;
        cur++;
        cout << cnt << " ";
    }
}
