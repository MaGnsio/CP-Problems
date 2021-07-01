//https://atcoder.jp/contests/abc201/tasks/abc201_b
#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int N;
    cin >> N;
    vector<pair<int, string>> V(N);
    for (int i = 0; i < N; ++i) {
        cin >> V[i].second >> V[i].first;
    }
    sort(V.begin(), V.end());
    cout << V[N - 2].second;
}
