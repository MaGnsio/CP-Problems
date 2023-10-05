/**
 *    author:  MaGnsi0
 *    created: 04.05.2023 17:49:26
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
        vector<string> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        cout << count(a.begin(), a.end(), a[0]) << "\n";
    }
}
