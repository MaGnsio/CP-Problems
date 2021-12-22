/**
 *    author:  MaGnsi0
 *    created: 20.11.2021 14:01:01
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int s, t, x;
    cin >> s >> t >> x;
    if (s < t) {
        cout << (x >= s && x < t ? "Yes" : "No");
    } else {
        cout << ((x >= s && x <= 23) || (x < t) ? "Yes" : "No");
    }
}
