/**
 *    author:  MaGnsi0
 *    created: 14.10.2021 14:31:20
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, p;
    cin >> n >> p;
    int res = 0;
    for (int i = 0; i < n; ++i) {
        int x; 
        cin >> x;
        res += (x < p);
    }
    cout << res;
}
