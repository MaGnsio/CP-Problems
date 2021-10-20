//https://vjudge.net/contest/433102#problem/P
#include <bits/stdc++.h>
using namespace std;

int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int n, mini = 0, maxi = 1023, l = 0, m = 0;
    cin >> n;
    while (n--) {
        char c;
        int x;
        cin >> c >> x;
        if (c == '|') {
            mini |= x;
            maxi |= x;
        }
        else if (c == '^') {
            mini ^= x;
            maxi ^= x;
        }
        else {
            mini &= x;
            maxi &= x;
        }
    }
    for (int b = 0; b < 10; ++b) {
        int b1 = ((1 << b) & mini);
        int b2 = ((1 << b) & maxi);
        if (b1 && b2) {
            l |= (1 << b);
        }
        if (!b1 && !b2) {
            l |= (1 << b);
            m |= (1 << b);
        }
        if (b1 && !b2) {
            m |= (1 << b);
        }
    }
    cout << 2 << "\n";
    cout << "| " << l << "\n";
    cout << "^ " << m << "\n";
}

