/**
 *    author:  MaGnsi0
 *    created: 06.03.2022 11:49:22
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
        long long sum = accumulate(a.begin(), a.end(), 0LL);
        if (sum == 0) {
            cout << 0 << "\n";
            continue;
        }
        if (sum - a[n - 1] < a[n - 1]) {
            cout << a[n - 1] - (sum - a[n - 1]) << "\n";
        } else {
            cout << 1 << "\n";
        }
    }
}
