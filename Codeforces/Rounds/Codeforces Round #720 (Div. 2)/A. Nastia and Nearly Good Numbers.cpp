//https://codeforces.com/contest/1521/problem/A
#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int T;
    cin >> T;
    while (T--) {
        long long A, B;
        cin >> A >> B;
        if (B == 1) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
            cout << A << " " << A * B << " " << A * (B + 1) << "\n";
        }
    }
}
