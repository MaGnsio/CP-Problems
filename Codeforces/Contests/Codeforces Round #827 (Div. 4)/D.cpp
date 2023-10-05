/**
 *    author:  MaGnsi0
 *    created: 14.10.2022 19:39:19
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 3;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(N, -1);
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            a[x] = i + 1;
        }
        int ans = -1;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (a[i] == -1 || a[j] == -1) {
                    continue;
                }
                if (__gcd(i, j) == 1) {
                    if (ans == -1 || ans < a[i] + a[j]) {
                        ans = a[i] + a[j];
                    }
                }
            }
        }
        cout << ans << "\n";
    }
}
