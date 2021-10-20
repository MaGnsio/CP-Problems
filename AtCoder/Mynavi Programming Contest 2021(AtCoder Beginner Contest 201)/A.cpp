//https://atcoder.jp/contests/abc201/tasks/abc201_a
#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    vector<int> V(3);
    for (int i = 0; i < 3; ++i) {
        cin >> V[i];
    }
    sort(V.begin(), V.end());
    cout << (V[2] - V[1] == V[1] - V[0] ? "Yes" : "No");
}
