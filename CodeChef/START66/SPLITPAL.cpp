/**
 *    author:  MaGnsi0
 *    created: 23.11.2022 16:48:42
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
        deque<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        int ans = 0;
        while ((int)a.size() > 1) {
            int x = a.front(), y = a.back();
            a.pop_back(), a.pop_front();
            if (x == y) {
                continue;
            }
            if (x > y) {
                a.push_front(x - y);
            } else {
                a.push_back(y - x);
            }
            ans++;
        }
        cout << ans << "\n";
    }
}
