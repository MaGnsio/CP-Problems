/**
 *    author:  MaGnsi0
 *    created: 29.11.2022 17:49:15
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        vector<int> a(3);
        for (int i = 0; i < 3; ++i) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        cout << a[1] << "\n";
    }
}
