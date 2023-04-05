/**
 *    author:  MaGnsi0
 *    created: 22.12.2021 01:58:53
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("input1.txt", "r", stdin);
    int x;
    vector<int> a;
    while (cin >> x) {
        a.push_back(x);
    }
    int res = 0;
    for (int i = 1; i < (int)a.size(); ++i) {
        res += (a[i] > a[i - 1]);
    }
    cout << res;
}
