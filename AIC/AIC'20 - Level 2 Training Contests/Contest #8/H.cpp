//https://vjudge.net/contest/433801#problem/H
#include <bits/stdc++.h>
using namespace std;

int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int t;
    cin >> t;
    while (t--) {
        int l, r, ans = 0;
        cin >> l >> r;
        for (int i = 31; i >= 0; --i) {
            if (((1 << i) & l) ^ ((1 << i) & r)) {
                break;
            }
            if (((1 << i) & l) & ((1 << i) & r)) {
                ans |= (1 << i);
            }
        }
        cout << ans << "\n";
    }
}
