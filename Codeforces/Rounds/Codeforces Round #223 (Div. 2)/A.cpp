/**
 *    author:  MaGnsi0
 *    created: 08/08/2021 19:56:41
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
    int l = 0, r = n - 1, a = 0, b = 0, cur = 0;
    while (l <= r) {
        if (v[l] > v[r]) {
            if (!cur) {
                a += v[l];
            } else {
                b += v[l];
            }
            l++;
        } else {
            if (!cur) {
                a += v[r];
            } else {
                b += v[r];
            }
            r--;
        }
        cur ^= 1;
    }
    cout << a << " " << b;
}
