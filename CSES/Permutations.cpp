/**
 *    author:  MaGnsi0
 *    created: 15.11.2021 19:20:47
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    if (n == 1) {
        cout << 1;
        return 0;
    }
    if (n <= 3) {
        cout << "NO SOLUTION";
        return 0;
    }
    for (int i = n - (n % 2 == 0); i >= 1; i -= 2) {
        cout << i << " ";
    }
    for (int i = n - (n & 1); i >= 2; i -= 2) {
        cout << i << " ";
    }
}
