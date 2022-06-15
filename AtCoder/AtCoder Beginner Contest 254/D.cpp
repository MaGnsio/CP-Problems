/**
 *    author:  MaGnsi0
 *    created: 11.06.2022 04:16:05
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    map<int, int> cnt;
    for (int i = 0; i < n; ++i) {
        int a = i + 1, x = 1;
        for (int j = 2; j * j <= a; ++j) {
            int m = 0;
            while (a % j == 0) {
                a /= j;
                m++;
            }
            if (m & 1) {
                x *= j;
            }
        }
        if (a > 1) {
            x *= a;
        }
        cnt[x]++;
    }
    int ans = n;
    for (auto& [x, y] : cnt) {
        ans += y * (y - 1);
    }
    cout << ans;
}
