/**
 *    author:  MaGnsi0
 *    created: 10.08.2024 15:01:12
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int x; cin >> x;
    int y; cin >> y;
    if (x < y) { swap(x, y); }
    cout << (n - x > x ? "No" : "Yes");
}
