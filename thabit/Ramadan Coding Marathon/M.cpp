/**
 *    author:  MaGnsi0
 *    created: 21.04.2022 11:20:38
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

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
        int64_t ans = 0, O = 0;
        vector<int64_t> F(N, 0);
        for (int i = 0; i < n; ++i) {
            ans += ((F[a[i]] + O) * (n - i));
            if (a[i] == 1) {
                O += (i + 1);
                continue;
            }
            for (int j = a[i]; j < N; j += a[i]) {
                F[j] += (i + 1);
            }
        }
        cout << ans << "\n";
    }
}
