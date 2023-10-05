/**
 *    author:  MaGnsi0
 *    created: 11.09.2023 17:55:47
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
        set<int> S;
        for (int i = 0; i < n; ++i) {
            int x; cin >> x;
            S.insert(x);
        }
        int missing = -1;
        for (int i = 0; i <= n; ++i) {
            if (S.count(i) == 0) {
                missing = i;
                break;
            }
        }
        cout << missing << endl;
        int y; cin >> y;
        while (y >= 0) {
            cout << y << endl;
            cin >> y;
        }
    }
}
