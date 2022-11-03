/**
 *    author:  MaGnsi0
 *    created: 01.08.2022 02:50:46
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    int odd = 0, even = 0;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        odd += (x & 1);
        even += !(x & 1);
    }
    cout << (abs(odd - even) <= 1 ? "Good" : "Not Good");
}
