/**
 *    author:  MaGnsi0
 *    created: 02.12.2023 21:37:40
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    vector<int> a(5);
    for (int i = 0; i < 5; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    cout << ((a[0] == a[2] && a[3] == a[4]) || (a[0] == a[1] && a[2] == a[4]) ? "Yes" : "No");
}
