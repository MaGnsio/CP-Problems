//https://vjudge.net/contest/435128#problem/N
#include <bits/stdc++.h>
using namespace std;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void solve (int& N, int& M, int& cnt, vector<vector<int>>& V, int i = 0, int j = 0) {
    if (i < 0 || i >= N || j < 0 || j >= M || !V[i][j]) {
        return;
    }
    if (i == N - 1 && j == M - 1) {
        cnt++;
        return;
    }
    V[i][j] = 0;
    for (int k = 0; k < 4; ++k) {
        solve(N, M, cnt, V, i + dx[k], j + dy[k]);
    }
    V[i][j] = 1;
}

int main () {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int N, M, cnt = 0;
    cin >> N >> M;
    vector<vector<int>> V(N, vector<int>(M));
    for (auto& x : V) {
        for (auto& y : x) {
            cin >> y;
        }
    }
    solve(N, M, cnt, V);
    cout << cnt;
}

