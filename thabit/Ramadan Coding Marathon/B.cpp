/**
 *    author:  MaGnsi0
 *    created: 05.04.2022 01:09:37
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
        int cnt = count(a.begin(), a.end(), a[n - 1]);
        cout << (cnt > 2 ? -1 : (cnt == 1 ? n : n - 1)) << "\n";
    }
}
