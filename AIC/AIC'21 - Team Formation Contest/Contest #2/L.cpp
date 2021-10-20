/**
 *    author:  MaGnsi0
 *    created: 17/07/2021 13:36:39
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int n, k;
    cin >> n >> k;
    vector<int> v(101, 0);
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        v[x]++;
    }
    for (int i = 1; i < 101; ++i) {
        v[i] += v[i - 1];
    }
    if (k) {
        cout << k - 2 * v[k - 1] + v[k];
    } else {
        cout << v[0];
    }
}
