/**
 *    author:  MaGnsi0
 *    created: 04.10.2023 16:09:33
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int a, b, n;
    cin >> a >> b >> n;
    int ans = 1, a_end = a, b_end = b;
    while (b_end < n) {
        a_end = b_end;
        b_end = (a_end - a) + b;
        ans += 2;
    }
    cout << ans;
}
