//https://vjudge.net/contest/435128#problem/J
#include <bits/stdc++.h>
using namespace std;

int F(int n) {
    if (n <= 1) {
        return 1;
    }
    return n * F(n - 1);
}

void solve(int& N, vector<int>& V, unordered_set<int>& S, int& cnt, int idx = 0) {
    if (idx == N) {
        for (int i = 0; i < N; ++i) {
            cout << V[i];
            if (i != N - 1) {
                cout << " ";
            }
        }
        cnt--;
        if (cnt) {
            cout << "\n";
        }
    }
    for (int i = 1; i <= N; ++i) {
        if (S.count(i) == 0) {
            V[idx] = i;
            S.insert(i);
            solve(N, V, S, cnt, idx + 1);
            S.erase(i);
        }
    }
}

int main () {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int N, cnt;
    cin >> N;
    vector<int> V(N);
    unordered_set<int> S;
    cnt = F(N);
    solve(N, V, S, cnt);
}
