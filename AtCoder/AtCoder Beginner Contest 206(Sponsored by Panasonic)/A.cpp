/**
 *    author:  MaGnsi0
 *    created: 19/06/2021 13:56:49
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int n;
    cin >> n;
    n *= 1.08;
    if (n < 206) {
        cout << "Yay!";
    } else if (n == 206) {
        cout << "so-so";
    } else {
        cout << ":(";
    }
}
