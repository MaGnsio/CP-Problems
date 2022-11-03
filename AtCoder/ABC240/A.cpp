/**
 *    author:  MaGnsi0
 *    created: 23.02.2022 01:32:46
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int a, b;
    cin >> a >> b;
    cout << (abs(a - b) == 1 || (a == 1 && b == 10) ? "Yes" : "No");
}
