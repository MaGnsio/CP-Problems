/**
 *    author:  MaGnsi0
 *    created: 04/06/2021 19:08:04
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int n;
    cin >> n;
    vector<long long> v(n);
    for (auto& x : v) {
        cin >> x;
    }
    long long last = -1;
    for (int i = n - 1; i > 0; --i) {
        if (v[i] <= 0LL && !(v[i] == 0 && last > 0)) {
            v[i - 1] += v[i];
            v[i] = 1e10;
        }
        if (v[i] != 1e10 && last == -1) {
            last = v[i];
        }
    }
    for (auto& x : v) {
        if (x != 1e10) {
            cout << x << " ";
        }
    }
}
