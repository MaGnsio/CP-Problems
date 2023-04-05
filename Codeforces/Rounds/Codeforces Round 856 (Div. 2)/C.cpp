/**
 *    author:  MaGnsi0
 *    created: 04.03.2023 19:49:55
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
        int ans = 0;
        multiset<int> b;
        for (int i = 0; i < n; ++i) {
            b.insert(a[i]); ans++;
            while (*b.begin() < ans) { b.erase(b.begin()); ans--; }
            cout << ans << " ";
        }
        cout << "\n";
    }
}
