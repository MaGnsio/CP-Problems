//https://vjudge.net/contest/419722#problem/V
#include <bits/stdc++.h>
using namespace std;

int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    long long n, m, l, r;
    cin >> n >> m >> l >> r;
    if (n > LLONG_MAX / m) {
        cout << 0;
    }
    else {
        cout << ((r) / (n * m / gcd (n, m))) - ((l - 1) / (n * m / gcd (n, m)));
    }
}

