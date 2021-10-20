/**
 *    author:  MaGnsi0
 *    created: 13.10.2021 16:27:20
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
        vector<int> a(k);
        for (int i = 0; i < k; ++i) {
            cin >> a[i];
        }
        sort(a.begin(), a.end(), greater<int>());
        int cur = 0, res = 0;
        for (int i = 0; i < k; ++i) {
            if (cur >= a[i]) {
                break;
            }
            int x = n - a[i];
            cur += x;
            res++;
        }
        cout << res << "\n";
    }
}
