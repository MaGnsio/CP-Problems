/**
 *    author:  MaGnsi0
 *    created: 13.10.2024 22:36:08
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int m; cin >> m;
        int happy = 0, odds = 0;
        for (int i = 0; i < n; ++i) {
            int x; cin >> x;
            m -= x / 2; happy += x - (x % 2); odds += x % 2;
        }
        int happy_alone = 0;
        for (int put_alone = 0; put_alone <= odds; ++put_alone) {
            if (((odds - put_alone) % 2 == 0) && (odds - put_alone) / 2 <= (m - put_alone)) {
                happy_alone = put_alone;
            }
        }
        cout << happy + happy_alone << "\n";
    }
}
