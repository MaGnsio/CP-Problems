/**
 *    author:  MaGnsi0
 *    created: 24/09/2021 17:34:32
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int n;
    cin >> n;
    vector<long long> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    long long minx = 0, maxx = 1e8, curx = 0;
    for (int i = 0; i < n; ++i) {
        curx = v[i] - curx;
        if (i & 1) {
            minx = max(minx, -1 * curx);
        } else {
            maxx = min(maxx, curx);
        }
    }
    cout << max(maxx - minx + 1, 0LL);
}
