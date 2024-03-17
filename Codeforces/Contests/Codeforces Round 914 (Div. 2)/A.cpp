/**
 *    author:  MaGnsi0
 *    created: 19.12.2023 13:52:47
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int a; cin >> a;
        int b; cin >> b;
        int x1; cin >> x1;
        int y1; cin >> y1;
        int x2; cin >> x2;
        int y2; cin >> y2;
        map<pair<int, int>, int> mp;
        for (int sign1 : {-1, 1}) {
            for (int sign2 : {-1, 1}) {
                for (int x : {a, b}) {
                    {
                        int ax = x1 + sign1 * x;
                        int ay = y1 + sign2 * (x == a ? b : a);
                        mp[{ax, ay}]++;
                    }
                    {
                        int ax = x2 + sign1 * x;
                        int ay = y2 + sign2 * (x == a ? b : a);
                        mp[{ax, ay}]++;
                    }
                    if (a == b) { break; }
                }
            }
        }
        int ans = 0;
        for (auto [_, f] : mp) {
            ans += f == 2;
        }
        cout << ans << "\n";
    }
}
