//https://vjudge.net/contest/435128#problem/O
#include <bits/stdc++.h>
using namespace std;

bool solve(string& S, string P, map<char, string> M, int i = 0, int j = 0)
{
    if (i == S.size() && j == P.size()) {
        return true;
    }
    if (i == S.size() || j == P.size()) {
        return false;
    }
    if (M.find(P[j]) != M.end())
    {
        if (S.substr(i, M[P[j]].size()) != M[P[j]]) {
            return false;
        }
        return solve(S, P, M, i + M[P[j]].size(), j + 1);
    }
    for (int k = 1; k <= S.size() - i; k++)
    {
        M[P[j]] = S.substr(i, k);
        if (solve(S, P, M, i + k, j + 1)) {
            return true;
        }
        M.erase(P[j]);
    }
    return false;
}

int main () {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int T;
    cin >> T;
    while (T--) {
        string S, P;
        map<char, string> M;
        cin >> S >> P;
        cout << (solve(S, P, M) ? "YES\n" : "NO\n");
    }
}

