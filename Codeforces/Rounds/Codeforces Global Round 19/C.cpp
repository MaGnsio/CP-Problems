/**
 *    author:  MaGnsi0
 *    created: 12.02.2022 16:29:57
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
        long long res = 0;
        for (int i = 1; i < n - 1; ++i) {
            res += (a[i] + 1) / 2;
        }
        cout << (*max_element(a.begin() + 1, a.begin() + n - 1) == 1 || ((n == 3) && (a[1] & 1)) ? -1LL : res) << "\n";
    }
}
