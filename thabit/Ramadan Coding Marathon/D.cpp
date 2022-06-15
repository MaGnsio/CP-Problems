/**
 *    author:  MaGnsi0
 *    created: 07.04.2022 17:58:31
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
        vector<long long> b(n);
        b[0] = a[0];
        for (int i = 1; i < n; ++i) {
            b[i] += 1LL * (b[i - 1] + a[i]);
        }
        int s = 0;
        while (true) {
            long long average = (b[n - 1] - (s ? b[s - 1] : 0) + n - s - 1) / (n - s);
            int l = s, r = n - 1, ns = -1;
            while (l <= r) {
                int m = (l + r) / 2;
                if (a[m] < average) {
                    ns = m;
                    l = m + 1;
                } else {
                    r = m - 1;
                }
            }
            if (ns == -1) {
                break;
            }
            s = ns + 1;
        }
        for (int i = s; i < n; ++i) {
            cout << a[i] << " ";
        }
        cout << "\n";
    }
}
