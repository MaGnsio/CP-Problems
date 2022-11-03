/**
 *    author:  MaGnsi0
 *    created: 18/09/2021 13:55:09
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int x;
    cin >> x;
    if (x < 40) {
        cout << 40 - x;
    } else if (x < 70) {
        cout << 70 - x;
    } else if (x < 90) {
        cout << 90 - x;
    } else {
        cout << "expert";
    }
}
