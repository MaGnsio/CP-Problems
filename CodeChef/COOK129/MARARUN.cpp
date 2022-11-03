//https://www.codechef.com/COOK129C/problems/MARARUN
#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int T;
    cin >> T;
    while (T--) {
        int D, d, A, B, C;
        cin >> D >> d >> A >> B >> C;
        if (D * d >= 42) {
            cout << C << "\n";
        } else if (D * d >= 21) {
            cout << B << "\n";
        } else if (D * d >= 10) {
            cout << A << "\n";
        } else {
            cout << 0 << "\n";
        }
    }
}
