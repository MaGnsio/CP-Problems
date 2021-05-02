//https://vjudge.net/contest/435128#problem/K
#include <bits/stdc++.h>
using namespace std;

void solve(int N, int R, vector<int>& V, unordered_set<int> S, int idx = 0) {
    if (idx == R) {
        for (auto& x : V) {
            cout << x << " ";
        }
        cout << "\n";
        return;
    }
    for (int i = 1; i <= N; ++i) {
        if (S.count(i) == 0) {
            V[idx] = i;
            S.insert(i);
            solve(N, R, V, S, idx + 1);
            S.erase(i);
        }
    }
}

int main () {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int N, R;
    cin >> N >> R;
    vector<int> V(R);
    unordered_set<int> S;
    solve(N, R, V, S);
}

