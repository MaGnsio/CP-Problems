//https://vjudge.net/contest/435043#problem/J
#include <bits/stdc++.h>
using namespace std;

bool solve(int N, int M, int r, int c, int& cnt, vector<vector<char>>& V, vector<vector<bool>>& Visited) {
    if (Visited[r][c] || V[r][c] == '#') {
        return true;
    }
    if (V[r][c] == 'B') {
        return false;
    }
    if (V[r][c] == 'G') {
        V[r][c] = '.';
        cnt++;
    }
    Visited[r][c] = true;
    bool A = solve(N, M, r + 1, c, cnt, V, Visited);
    bool B = solve(N, M, r - 1, c, cnt, V, Visited);
    bool C = solve(N, M, r, c + 1, cnt, V, Visited);
    bool D = solve(N, M, r, c - 1, cnt, V, Visited);
    return (A && B && C && D);
}

int main () {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int T;
    cin >> T;
    while (T--) {
        int N, M, G = 0, cnt = 0;
        cin >> N >> M;
        vector<vector<char>> V(N + 2, vector<char>(M + 2, '#'));
        vector<vector<bool>> Visited(N + 2, vector<bool>(M + 2, false));
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= M; ++j) {
                cin >> V[i][j];
                G += (V[i][j] == 'G');
            }
        }
        bool OK = true;
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= M; ++j) {
                if (V[i][j] == 'B') {
                    if (V[i + 1][j] == '.') {
                        V[i + 1][j] = '#';
                    }
                    if (V[i - 1][j] == '.') {
                        V[i - 1][j] = '#';
                    }
                    if (V[i][j + 1] == '.') {
                        V[i][j + 1] = '#';
                    }
                    if (V[i][j - 1] == '.') {
                        V[i][j - 1] = '#';
                    }
                }
            }
        }
        OK = (solve(N, M, N, M, cnt, V, Visited) && cnt == G);
        cout << (OK ? "Yes\n" : "No\n");
    }
}
