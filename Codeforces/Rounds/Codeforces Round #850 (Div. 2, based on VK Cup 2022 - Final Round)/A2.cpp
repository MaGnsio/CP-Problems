/**
 *    author:  MaGnsi0
 *    created: 05.02.2023 14:12:15
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
        int m = 1, turn = 1, j = 2;
        vector<int> a(2), b(2);
        a[0] = 1;
        while (m < n) {
            int take = min(j, n - m);
            int white = (take / 2) + (take % 2) * (m % 2 == 0);
            int black = (take / 2) + (take % 2) * (m & 1);
            a[turn] += white;
            b[turn] += black;
            m += take;
            j++;
            take = min(j, n - m);
            white = (take / 2) + (take % 2) * (m % 2 == 0);
            black = (take / 2) + (take % 2) * (m & 1);
            a[turn] += white;
            b[turn] += black;
            m += take;
            j++;
            turn ^= 1;
        }
        cout << a[0] << " " << b[0] << " " << a[1] << " " << b[1] << "\n";
    }
}
