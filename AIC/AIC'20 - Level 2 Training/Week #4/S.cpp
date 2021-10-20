//https://vjudge.net/contest/433102#problem/S
#include <bits/stdc++.h>
using namespace std;

int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    //we want to find the largest power of two that R have and L don't
    long long l, r, k;
    cin >> l >> r;
    if (l == r) {
        cout << 0;
        return 0;
    }
    bitset<64> a(l), b(r);
    for (long long i = 0; i < 64; ++i) {
        if (b[i] && !a[i]) {
            k = i;
        }
    }
    cout << (1LL << (k + 1)) - 1;
}

