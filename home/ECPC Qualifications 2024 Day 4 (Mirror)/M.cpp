/**
 *    author:  MaGnsi0
 *    created: 25.07.2024 16:03:27
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int a[3];
    cin >> a[0] >> a[1] >> a[2];
    sort(a, a + 3);
    cout << a[1];
}
