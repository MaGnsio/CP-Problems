/**
 *    author:  MaGnsi0
 *    created: 26.09.2022 19:51:28
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
        if (count(a.begin(), a.end(), 1)) {
            cout << "CHEF\n";
            continue;
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans = (ans + max(0, a[i] - 2)) % 2;
        }
        cout << (ans ? "CHEF" : "CHEFINA") << "\n";
    }
}
