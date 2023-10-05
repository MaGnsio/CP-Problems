/**
 *    author:  MaGnsi0
 *    created: 25/06/2021 23:14:06
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> v(n);
        iota(v.begin(), v.end(), 1);
        if (n & 1) {
            v[0] = 3, v[1] = 1, v[2] = 2;
            for (int i = 3; i < n; i += 2) {
                swap(v[i], v[i + 1]);
            }
        } else {
            for (int i = 0; i < n; i += 2) {
                swap(v[i], v[i + 1]);
            }
        }
        for (auto& x : v) {
            cout << x << " ";
        }
        cout << "\n";
    }
}
