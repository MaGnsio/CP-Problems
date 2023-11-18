/**
 *    author:  MaGnsi0
 *    created: 13.10.2023 19:35:01
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int A, B;
    cin >> A >> B;
    for (int i = 1; i <= 6; ++i) {
        for (int j = 1; j <= 6; ++j) {
            for (int k = 1; k <= 6; ++k) {
                int a = 0, b = 0;
                if (i == 1 || i == 4) {
                    a += i;
                } else {
                    b += i;
                }
                if (j == 1 || j == 4) {
                    a += j;
                } else {
                    b += j;
                }
                if (k == 1 || k == 4) {
                    a += k;
                } else {
                    b += k;
                }
                if (a == A && b == B) {
                    cout << "Yes";
                    return 0;
                }
            }
        }
    }
    cout << "No";
}
