/**
 *    author:  MaGnsi0
 *    created: 14.04.2023 22:14:27
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n, 0);
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        if (a[x - 1] || x > n) {
            cout << "NO\n";
            return 0;
        }
        a[x - 1]++;
    }
    cout << (count(a.begin(), a.end(), 0) == 0 ? "YES" : "NO") << "\n";
}
