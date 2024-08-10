/**
 *    author:  MaGnsi0
 *    created: 10.08.2024 15:13:22
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int Q; cin >> Q;
    int ans = 0;
    vector<int> balls(N);
    while (Q--) {
        int t; cin >> t;
        if (t == 1) {
            int x; cin >> x;
            ans += balls[x] == 0;
            balls[x]++;
        } else if (t == 2) {
            int x; cin >> x;
            balls[x]--;
            ans -= balls[x] == 0;
        } else {
            cout << ans << "\n";
        }
    }
}
