/**
 *    author:  MaGnsi0
 *    created: 08.02.2025 13:59:41
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int a[3];
    for (int& x : a) { cin >> x; }
    sort(a, a + 3);
    cout << (a[0] * a[1] == a[2] ? "Yes" : "No");
}
