/**
 *    author:  MaGnsi0
 *    created: 28.11.2021 16:27:39
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
        long long sum = 0, add = 1;
        vector<long long> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            while (a[i] % 2 == 0) {
                a[i] /= 2;
                add *= 2LL;
            }
            sum += a[i];
        }
        long long res = sum;
        for (int i = 0; i < n; ++i) {
            res = max(res, sum - a[i] + (a[i] * add));
        }
        cout << res << "\n";
    }
}
