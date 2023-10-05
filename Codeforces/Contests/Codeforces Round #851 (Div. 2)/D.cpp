/**
 *    author:  MaGnsi0
 *    created: 11.02.2023 19:09:23
**/
#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<int> P2(n, 1);
    for (int i = 1; i < n; ++i) {
        P2[i] = 2 * P2[i - 1];
        P2[i] %= MOD;
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int low = 0, high = i - 1, L = i, R = j;
            while (low <= high) {
                int mid = (low + high) / 2;
                if (a[i] - a[mid] <= a[j] - a[i]) {
                    L = mid;
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
            low = j + 1, high = n - 1;
            while (low <= high) {
                int mid = (low + high) / 2; 
                if (a[mid] - a[j] < a[j] - a[i]) {
                    R = mid;
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }

            }
            ans += P2[n + L - R - 1];
            ans %= MOD;
        }
    }
    cout << ans;
}
