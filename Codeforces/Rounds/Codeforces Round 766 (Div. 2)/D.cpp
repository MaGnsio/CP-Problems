/**
 *    author:  MaGnsi0
 *    created: 15.05.2023 20:32:39
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<bool> a(N, false);
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        a[x] = true;
    }
    for (int i = 1; i < N; ++i) {
        int g = 0;
        for (int j = i; j < N; j += i) {
            if (a[j]) { g = __gcd(g, j); }
            if (g == i) {
                a[i] = true;
                break;
            }
        }
    }
    int ans = -n;
    for (int i = 0; i < N; ++i) {
        ans += a[i];
    }
    cout << ans;
}
