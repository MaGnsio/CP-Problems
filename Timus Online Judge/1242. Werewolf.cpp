//https://acm.timus.ru/problem.aspx?space=1&num=1242
#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>& G, vector<bool>& V, vector<int>& Sus, int i) {
    V[i] = true;
    if (Sus[i] == 1) {
        Sus[i] = 0;
    }
    for (auto& x : G[i]) {
        if(!V[x]) {
            dfs(G, V, Sus, x);
        }
    }
}

int main () {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int N;
    cin >> N;
    vector<vector<int>> P(N + 1), C(N + 1);
    cin.ignore();
    while (true) {
        string S;
        getline(cin, S);
        if (S == "BLOOD") {
            break;
        }
        int u = 0, v = 0, i = 0;
        while (S[i] != ' ') {
            u = (u * 10) + (S[i] - '0');
            i++;
        }
        while (i + 1 < S.size()) {
            v = (v * 10) + (S[i + 1] - '0');
            i++;
        }
        P[u].push_back(v);
        C[v].push_back(u);
    }
    int x;
    vector<int> Sus(N + 1, 1);
    while(cin >> x) {
        Sus[x] = -1;
    }
    vector<bool> V1(N + 1, false), V2(N + 2, false);
    for (int i = 1; i <= N; ++i) {
        if (Sus[i] == -1) {
            dfs(P, V1, Sus, i);
            dfs(C, V2, Sus, i);
        }
    }
    if (count(Sus.begin(), Sus.end(), 1) == 1) {
        cout << 0;
    } else {
        for (int i = 1; i <= N; ++i) {
            if (Sus[i] == 1) {
                cout << i << " ";
            }
        }
    }
}
