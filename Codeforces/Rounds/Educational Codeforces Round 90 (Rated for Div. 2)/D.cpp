/**
 *    author:  MaGnsi0
 *    created: 15.11.2021 18:56:20
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
        vector<long long> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        long long sum = 0;
        for (int i = 0; i < n; i += 2) {
            sum += a[i];
        }
        vector<long long> v1, v2;
        for (int i = 0; i + 1 < n; i += 2) {
            v1.push_back(a[i + 1] - a[i]);
        }
        for (int i = 1; i + 1 < n; i += 2) {
            v2.push_back(a[i] - a[i + 1]);
        }
        long long maxd = 0, cur = 0;
        for (int i = 0; i < (int)v1.size(); ++i) {
            cur += v1[i];
            maxd = max(cur, maxd);
            cur = max(cur, 0LL);
        }
        cur = 0;
        for (int i = 0; i < (int)v2.size(); ++i) {
            cur += v2[i];
            maxd = max(cur, maxd);
            cur = max(cur, 0LL);
        }
        cout << sum + maxd << "\n";
    }
}
