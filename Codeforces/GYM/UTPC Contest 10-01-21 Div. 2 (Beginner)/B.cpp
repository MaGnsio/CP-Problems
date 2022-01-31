/**
 *    author:  MaGnsi0
 *    created: 22.12.2021 19:29:57
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, k;
    cin >> n >> k;
    int a = 0;
    for (int i = 0, x; i < n; ++i) {
        cin >> x;
        a = max(x, a);
    }
    cout << (k > a ? "Easy Win!" : "Difficult Loss");
}
