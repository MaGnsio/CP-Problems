/**
 *    author:  MaGnsi0
 *    created: 09.04.2022 16:27:51
**/
#include <bits/stdc++.h>

using namespace std;

int N = (1 << 15);

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    auto F = [&](int x) {
        int ans = INT_MAX;
        for (int i = 0; i < 20; ++i) {
            int cnt = i, y = x + i;
            while (y % N) {
                y *= 2;
                cnt++;
            }
            ans = min(ans, cnt);
        }
        return ans;
    };
    for (int i = 0; i < n; ++i) {
        cout << F(a[i]) << " ";
    }
}
