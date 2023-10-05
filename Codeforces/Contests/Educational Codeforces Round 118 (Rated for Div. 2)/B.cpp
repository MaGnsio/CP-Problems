/**
 *    author:  MaGnsi0
 *    created: 01.12.2021 16:24:10
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        vector<int> res;
        for (int i = 1; (int)res.size() != n / 2; ++i) {
            res.push_back(a[i]);
        }
        for (int i = 0; i < n / 2; ++i) {
            cout << res[i] << " " << a[0] << "\n";
        }
    }
}
