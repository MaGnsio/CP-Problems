//https://vjudge.net/contest/435128#problem/L
#include <bits/stdc++.h>
using namespace std;

void solve(int& N, vector<vector<char>>& V, unordered_set<int>& C, unordered_set<int>& L, unordered_set<int>& R, int row = 0) {
    if (row == N) {
        for (auto& x : V) {
            for (auto& y : x) {
                cout << y;
            }
            cout << "\n";
        }
        cout << "\n";
        return;
    }
    for (int col = 0; col < N; ++col) {
        if (C.count (col) == 0 && L.count(row + col) == 0 && R.count(row - col) == 0) {
            V[row][col] = 'Q';
            C.insert(col);
            L.insert(row + col);
            R.insert(row - col);
            solve (N, V, C, L, R, row + 1);
            V[row][col] = '.';
            C.erase(col);
            L.erase(row + col);
            R.erase(row - col);
        }
    }
}

int main () {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int N;
    cin >> N;
    vector<vector<char>> V(N, vector<char> (N, '.'));
    unordered_set<int> C, L, R;
    solve(N, V, C, L, R);
}

