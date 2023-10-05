/**
 *    author:  MaGnsi0
 *    created: 22.04.2022 09:57:28
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        if (n <= 1399) {
            cout << "Division 4\n";
        } else if (n <= 1599) {
            cout << "Division 3\n";
        } else if (n <= 1899) {
            cout << "Division 2\n";
        } else {
            cout << "Division 1\n";
        }
    }
}
