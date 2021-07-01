//https://codeforces.com/gym/101149/problem/I
#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int N, M;
    cin >> N >> M;
    vector<pair<int, vector<int>>> V(N);
    vector<int> F(N + 1, 1);
    for (int i = 0; i < N; ++i) {
        V[i].first = i + 1;
    }
    for (int i = 0; i < M; ++i) {
        int x, y;
        cin >> x >> y;
        V[x - 1].second.push_back(y);
        V[y - 1].second.push_back(x);
    }
    sort(V.begin(), V.end(),[&](pair<int, vector<int>> A, pair<int, vector<int>> B) {
            return (A.second.size() < B.second.size());
            });
    F[V[0].first] = 0;
    for (int i = 0; i < V[0].second.size(); ++i) {
        F[V[0].second[i]] = 0;
    }
    for (int i = 1; i <= N; ++i) {
        cout << F[i] << " ";
    }
}

