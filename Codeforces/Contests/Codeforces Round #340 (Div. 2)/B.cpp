/**
 *    author:  MaGnsi0
 *    created: 25/09/2021 03:34:10
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
    if (count(v.begin(), v.end(), 1) == 0) {
        cout << 0;
        return 0;
    }
    long long res = 1;
    for (int i = 0, last_one = -1; i < n; ++i) {
        if (v[i] == 1) {
            if (last_one == -1) {
                last_one = i;
            } else {
                res *= (long long)(i - last_one);
                last_one = i;
            }
        }
    }
    cout << res;
}
