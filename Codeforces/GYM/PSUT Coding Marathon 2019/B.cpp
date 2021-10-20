/**
 *    author:  MaGnsi0
 *    created: 21/09/2021 20:56:52
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int n;
    cin >> n;
    vector<int> v(n), p(10);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    for (int i = 0; i < 10; ++i) {
        cin >> p[i];
    }
    sort(v.begin(), v.end());
    sort(p.begin(), p.end());
    cout << (v[0] >= p[0] ? 10 : v[0]);
}
