/**
 *    author:  MaGnsi0
 *    created: 05.02.2023 09:10:57
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int64_t n;
    cin >> n;
    if (n % 5) {
        cout << "NO";
    } else {
        cout << n / 15 + (n % 15 != 0);
    }
}
