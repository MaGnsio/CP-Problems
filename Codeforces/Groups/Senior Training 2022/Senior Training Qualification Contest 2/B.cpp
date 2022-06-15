/**
 *    author:  MaGnsi0
 *    created: 12.03.2022 22:00:39
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("adhm.in", "r", stdin);
    int T;
    cin >> T;
    while (T--) {
        int n, s, x;
        cin >> n >> s >> x;
        if (s < n) {
            cout << "Methat";
        } else if (s == n) {
            cout << (x >= s ? "Adhm" : "Methat");
        } else {
            if (s < x) {
                cout << "Adhm";
            } else {
                cout << ((x > n) || ((x == n) && (s % x == 0)) ? "Adhm" : "Methat");
            }
        }
        cout << "\n";
    }
}
