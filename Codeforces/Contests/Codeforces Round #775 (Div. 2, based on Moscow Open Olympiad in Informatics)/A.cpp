/**
 *    author:  MaGnsi0
 *    created: 06.03.2022 11:49:21
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
        int l = 0, r = n - 1;
        for (int i = 1; i < n; ++i) {
            if (a[i] == 0) {
                break;
            }
            l++;
        }
        for (int i = n - 2; i >= 0; --i) {
            if (a[i] == 0) {
                break;
            }
            r--;
        }
        cout << (l > r ? 0 : r - l) << "\n";
    }
}
