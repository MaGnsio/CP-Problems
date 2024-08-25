/**
 *    author:  MaGnsi0
 *    created: 24.08.2024 11:07:53
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int evens = 0, odds = 0, ones = 0;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        if (x == 0) { continue; }
        evens += x % 2 == 0;
        odds += x % 2 == 1;
        ones += x == 1;
    }
    if (evens == 0) {
        cout << (odds == 0 ? 0 : (ones == odds ? 1 : 2));
    } else {
        cout << (odds == 0 ? 1 : 2);
    }
}
