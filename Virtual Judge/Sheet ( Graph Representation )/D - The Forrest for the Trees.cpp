//https://vjudge.net/contest/372876#problem/D
#include <bits/stdc++.h>
using namespace std;

void Fill(vector<vector<int>>& V, vector<int>& F) {
    string s;
    while (cin >> s && s[0] != '*') {
        V[s[1] - 'A'].push_back(s[3] - 'A');
        V[s[3] - 'A'].push_back(s[1] - 'A');
    }
    cin >> s;
    for (int i = 0; i < s.size(); i += 2) {
        F[s[i] - 'A'] = 0;
    }
}

void dfs(vector<vector<int>>& V, vector<int>& F, int i) {
    if (F[i] != 0) {
        return;
    }
    F[i] = 1;
    for (int j = 0; j < V[i].size(); ++j) {
        dfs(V, F, V[i][j]);
    }
}

int main () {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int T;
    cin >> T;
    while (T--) {
        int X = 0, Y = 0;
        vector<vector<int>> V(26);
        vector<int> F(26, -1);
        Fill(V, F);
        for (int i = 0; i < 26; ++i) {
            if (F[i] != 0) {
                continue;
            }
            if (V[i].empty()) {
                F[i] = 1;
                Y++;
                continue;
            }
            dfs(V, F, i);
            X++;
        }
        cout << "There are " << X << " tree(s) and " << Y << " acorn(s).\n";
    }
}

