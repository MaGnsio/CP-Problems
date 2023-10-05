/**
 *    author:  MaGnsi0
 *    created: 27.07.2023 17:44:31
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        vector<pair<int, int>> a(n);
        for (int i = 0; i < n; ++i) {
            int x; cin >> x;
            int val = (x / k) - (x % k == 0);
            a[i] = {x - k * val, -i};
        }
        sort(a.rbegin(), a.rend());
        for (int i = 0; i < n; ++i) {
            cout << 1 - a[i].second << " ";
        }
        cout << "\n";
    }
}
