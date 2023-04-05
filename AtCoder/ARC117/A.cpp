/**
 *    author:  MaGnsi0
 *    created: 09.11.2022 20:43:52
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int64_t A, B;
    cin >> A >> B;
    if (A >= B) {
        for (int i = 1; i <= A; ++i) {
            cout << i << " ";
        }
        for (int i = 1; i < B; ++i) {
            cout << -i << " ";
        }
        cout << (B * (B - 1) - A * (A + 1)) / 2;
    } else {
        for (int i = 1; i < A; ++i) {
            cout << i << " ";
        }
        for (int i = 1; i <= B; ++i) {
            cout << -i << " ";
        }
        cout << (B * (B + 1) - A * (A - 1)) / 2;
    }
}
