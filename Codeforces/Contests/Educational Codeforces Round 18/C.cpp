/**
 *    author:  MaGnsi0
 *    created: 27/09/2021 13:51:34
**/
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5, OO = 2e8;

int n;
int dp[N][3];
string s;

int solve(int i, int j) {
    if (i == n) {
        return (j != 0) * (-OO);
    }
    int& ret = dp[i][j];
    if (ret != -1) {
        return ret;
    }
    int d = s[i] - '0';
    ret = max(solve(i + 1, j), solve(i + 1, (j + d) % 3) + 1); 
    return ret;
}

string f(int i, int j) {
    if(i == n) {
        return "";
    }
    int a = solve(i, j);
    int b = solve(i + 1, j);
    int c = solve(i + 1, (j + s[i] - '0') % 3) + 1;
    if (a == b) {
        return f(i + 1, j);
    } else {
        return s[i] + f(i + 1, (j + s[i] - '0') % 3);
    }
}

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    memset(dp, -1, sizeof dp);
    cin >> s;
    n = (int)s.size();
    int res = -1, start = -1, O = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] - '0' == 0) {
            O = 1;
            continue;
        }
        int k = solve(i + 1, (s[i] - '0') % 3) + 1;
        if (k > res) {
            res = k;
            start = i;
        }
    }
    if (res == -1) {
        cout << (O ? "0" : "-1");
    } else {
        string t = s[start] + f(start + 1, (s[start] - '0') % 3);
        cout << t;
    }
}
