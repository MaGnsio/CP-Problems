/**
 *    author:  MaGnsi0
 *    created: 11.11.2021 17:32:20
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    long long n;
    cin >> n;
    while (n != 1) {
        cout << n << " ";
        if (n & 1) {
            n *= 3;
            n++;
        } else {
            n /= 2;
        }
    }
    cout << 1;
}
