/**
 *    author:  MaGnsi0
 *    created: 14.09.2024 15:00:45
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    char ab, ac, bc;
    cin >> ab >> ac >> bc;
    if (ab != ac) {
        cout << "A";
    } else if (ab == bc) {
        cout << "B";
    } else {
        cout << "C";
    }
}
