//https://www.e-olymp.com/en/contests/15927/problems/164111
#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int N, M;
    cin >> N >> M;
    vector<int> V(N, 0);
    for (int i = 0; i < M; ++i) {
        int x, y;
        cin >> x >> y;
        V[x - 1]++, V[y - 1]++;
    }
    sort(V.begin(), V.end());
    cout << (V[0] == V[N - 1] ? "YES" : "NO");
}

