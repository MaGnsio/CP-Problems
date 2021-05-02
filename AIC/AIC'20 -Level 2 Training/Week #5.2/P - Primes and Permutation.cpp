//https://vjudge.net/contest/435128#problem/P
#include <bits/stdc++.h>
using namespace std;

bool isP(int n) {
    if (n < 2) {
        return false;
    }
    if (n < 4) {
        return true;
    }
    if (n % 2 == 0 || n % 3 == 0) {
        return false;
    }
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) {
            return false;
        }
    }
    return true;
}

void solve(int& N, vector<int>& V, unordered_set<int>& S, int idx = 1) {
    if (idx == N) {
        if (isP(V[0] + V[N - 1])) {
            for (auto& x : V) {
                cout << x << " ";
            }
            cout << "\n";
        }
        return;
    }
    for(int i = 2; i <= N; ++i) {
        if (S.count(i) == 0 && isP(V[idx - 1] + i)) {
            V[idx] = i;
            S.insert(i);
            solve(N, V, S, idx + 1);
            S.erase(i);
        }
    }
}

int main () {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int N;
    cin >> N;
    vector<int> V(N, 1);
    unordered_set<int> S;
    solve(N, V, S);
}

