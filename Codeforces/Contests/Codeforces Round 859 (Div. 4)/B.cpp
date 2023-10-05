/**
 *    author:  MaGnsi0
 *    created: 20.03.2023 02:06:49
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
        vector<int> a(2);
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            a[x % 2] += x;
        }
        cout << (a[0] > a[1] ? "YES" : "NO") << "\n";
    }
}
