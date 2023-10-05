/**
 *    author:  MaGnsi0
 *    created: 20.03.2022 13:30:14
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
        cout << (long long)(a[n - 1] + a[n - 2]) << "\n";
    }
}
