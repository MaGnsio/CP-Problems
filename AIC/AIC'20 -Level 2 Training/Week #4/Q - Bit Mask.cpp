//https://vjudge.net/contest/433102#problem/Q
#include <bits/stdc++.h>
using namespace std;

int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    long long n, l, u;
    while (cin >> n >> l >> u) {
        long long m = 0, s, r;
        for (long long b = 31; b >= 0; --b) {
            if ((1LL << b) & n) {
                s = (m | (1LL << b));
                if (s <= l) {
                    m |= (1LL << b);
                }
            }
            else {
                r = (m | (1LL << b));
                if (r <= u) {
                    m |= (1LL << b);
                }
            }
        }
        cout << m << "\n";
    }
}
