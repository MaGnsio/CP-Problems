//https://vjudge.net/contest/435128#problem/M
#include <bits/stdc++.h>
using namespace std;

void solve(int& N, int& M, vector<vector<int>>& V, vector<vector<int>>& A, vector<int>& F, vector<vector<bool>>& Visited, int i = 0, int j = 0) {
    if (i < 0 || i >= N || j < 0 || j >= M || Visited[i][j]) {
        return;
    }
    if (i == N - 1 && j == M - 1) {
        F.push_back(V[i][j]);
        A.push_back(F);
        F.pop_back();
        return;
    }
    Visited[i][j] = true;
    F.push_back(V[i][j]);
    solve(N, M, V, A, F, Visited, i + 1, j);
    solve(N, M, V, A, F, Visited, i, j + 1);
    Visited[i][j] = false;
    F.pop_back();
}

int main () {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int N, M;
    cin >> N >> M;
    vector<vector<int>> V(N, vector<int>(M)), A;
    vector<int> F;
    vector<vector<bool>> Visited(N, vector<bool>(M, false));
    for (auto& x : V) {
        for (auto& y : x) {
            cin >> y;
        }
    }
    solve(N, M, V, A, F, Visited);
    sort(A.begin(), A.end());
    for (auto& x : A) {
        for (auto& y : x) {
            cout << y << " ";
        }
        cout << "\n";
    }
}

