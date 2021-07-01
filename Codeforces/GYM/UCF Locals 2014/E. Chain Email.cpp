//https://codeforces.com/gym/102323/problem/E?fbclid=IwAR03cgilZ_sjTCqq54x7TTclALpbHScb8llDON4Xz0A0AhZOMrUMNJiRzSM
#include <bits/stdc++.h>
using namespace std;

bool dfs1(vector<vector<int>>& G, vector<bool>& V, int v, int s) {
    V[v] = 1;
    for (auto& u : G[v]) {
        if (u == s) {
            return true;
        }
        if (!V[u] && dfs1(G, V, u, s)) {
            return true;
        }
    }
    return false;
}

void dfs2(vector<vector<int>>& G, vector<bool>& V, int v) {
    V[v] = true;
    for (auto& u : G[v]) {
        if (!V[u]) {
            dfs2(G, V, u);
        }
    }
}

int main () {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        cout << "Chain Email #" << t << ":\n";
        int P, S;
        cin >> P >> S;
        map<int, string> M;
        for (int i = 1; i <= P; ++i) {
            string s;
            cin >> s;
            M[i] = s;
        }
        vector<vector<int>> G(P + 1);
        for (int u = 1; u <= P; ++u) {
            int N;
            cin >> N;
            for (int i = 0; i < N; ++i) {
                int v;
                cin >> v;
                G[u].push_back(v);
            }
        }
        vector<bool> A(P + 1, false), B(P + 1, false), C(P + 1, false);
        dfs2(G, A, S);
        for (int i = 1; i <= P; ++i) {
            if (A[i] && dfs1(G, B, i, i)) {
                C[i] = true;
            }
            fill(B.begin(), B.end(), false);
        }
        for (int i = 1; i <= P; ++i) {
            if (C[i]) {
                dfs2(G, C, i);
            }
        }
        if (count(C.begin(), C.end(), false) == P + 1) {
            cout << "Safe chain email!\n\n";
            continue;
        }
        for (int i = 1; i <= P; ++i) {
            if (C[i]) {
                cout << M[i] << " ";
            }
        }
        cout << "\n\n";
    }
}
