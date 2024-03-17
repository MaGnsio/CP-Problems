/**
 *    author:  MaGnsi0
 *    created: 25.11.2023 22:12:46
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int low; cin >> low;
    int high; cin >> high;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        if (low <= x && x <= high) {
            cout << x << " ";
        } else if (x < low) {
            cout << low << " ";
        } else {
            cout << high << " ";
        }
    }
}
