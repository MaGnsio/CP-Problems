/**
 *    author:  MaGnsi0
 *    created: 09/08/2021 16:50:17
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        vector<int> v(n);
        map<int, int> m;
        for (int i = 0; i < n; ++i) {
            cin >> v[i];
            m[v[i]] = i;
        }
        sort(v.begin(), v.end());
        for (int i = 1; i < n; ++i) {
            if (m[v[i]] != m[v[i - 1]] + 1) {
                k -= 1;
            }
            k -= (i == n - 1);
        }
        cout << (k < 0 ? "No" : "Yes") << "\n";
    }
}
