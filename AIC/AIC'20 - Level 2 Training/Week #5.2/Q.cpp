//https://vjudge.net/contest/435128#problem/Q
#include <bits/stdc++.h>
using namespace std;

void solve(vector<vector<int>>& V, unordered_set<int>& C, unordered_set<int>& L, unordered_set<int>& R, int& maxi, int& sum, int row = 0) {
    if (row == 8) {
        maxi = max(maxi, sum);
        return;
    }
    for (int col = 0; col < 8; ++col) {
        if (C.count(col) == 0 && L.count(row + col) == 0 && R.count(row - col) == 0) {
            sum += V[row][col];
            C.insert(col);
            L.insert(row + col);
            R.insert(row - col);
            solve(V, C, L, R, maxi, sum, row + 1);
            sum -= V[row][col];
            C.erase(col);
            L.erase(row + col);
            R.erase(row - col);
        }
    }
}

int main () {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int T;
    cin >> T;
    while (T--) {
        int maxi = INT_MIN, sum = 0;
        vector<vector<int>> V(8, vector<int>(8));
        unordered_set<int> C, L, R;
        for (auto& x : V) {
            for (auto& y : x) {
                cin >> y;
            }
        }
        solve(V, C, L, R, maxi, sum);
        cout << maxi << "\n";
    }
}

