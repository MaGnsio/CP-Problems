/**
 *    author:  MaGnsi0
 *    created: 23.10.2021 02:10:32
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 30;

void rotateR(int& n, int& m, vector<vector<char>>& a) {
    int r = m, c = n;
    int k = n - 1, l = 0;
    vector<vector<char>> b(r, vector<char>(c));
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            b[i][j] = a[k--][l];
        }
        k = n - 1, l++;
    }
    swap(n, m);
    a = b;
}

void rotateL(int& n, int& m, vector<vector<char>>& a) {
    int r = m, c = n;
    int k = 0, l = m - 1;
    vector<vector<char>> b(r, vector<char>(c));
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            b[i][j] = a[k++][l];
        }
        k = 0, l--;
    }
    swap(n, m);
    a = b;
}

void flipH(int n, int m, vector<vector<char>>& a) {
    int k = 0, l = m - 1;
    vector<vector<char>> b(n, vector<char>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            b[i][j] = a[k][l--];
        }
        k++, l = m - 1;
    }
    a = b;
}

void flipV(int n, int m, vector<vector<char>>& a) {
    int k = n - 1, l = 0;
    vector<vector<char>> b(n, vector<char>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            b[i][j] = a[k][l++];
        }
        k--, l = 0;
    }
    a = b;
}

int max_similarity(int n1, int m1, vector<vector<char>> a1, int n2, int m2, vector<vector<char>> a2) {
    int maxi = 0;
    for (int i = 0; i < n1; ++i) {
        for (int j = 0; j < m1; ++j) {
            int cnt = 0;
            for (int k = 0; k < n2; ++k) {
                for (int l = 0; l < m2; ++l) {
                    if (i + k >= n1 || j + l >= m1) {
                        continue;
                    }
                    cnt += (a1[i + k][j + l] == a2[k][l] && a2[k][l] == '#');
                }
            }
            maxi = max(maxi, cnt);
        }
    }
    for (int i = 0; i < n2; ++i) {
        for (int j = 0; j < m2; ++j) {
            int cnt = 0;
            for (int k = 0; k < n1; ++k) {
                for (int l = 0; l < m1; ++l) {
                    if (i + k >= n2 || j + l >= m2) {
                        continue;
                    }
                    cnt += (a2[i + k][j + l] == a1[k][l] && a1[k][l] == '#');
                }
            }
            maxi = max(maxi, cnt);
        }
    }
    return maxi;
}

set<vector<vector<char>>> mp;

void solve(int& res, int& n1, int& m1, vector<vector<char>>& a1, int& n2, int& m2, vector<vector<char>>& a2) {
    res = max(res, max_similarity(n1, m1, a1, n2, m2, a2));
    if (mp.count(a1)) {
        return;
    }
    mp.insert(a1);
    rotateL(n1, m1, a1);
    solve(res, n1, m1, a1, n2, m2, a2);
    rotateR(n1, m1, a1);
    rotateR(n1, m1, a1);
    solve(res, n1, m1, a1, n2, m2, a2);
    rotateL(n1, m1, a1);
    flipH(n1, m1, a1);
    solve(res, n1, m1, a1, n2, m2, a2);
    flipH(n1, m1, a1);
    flipV(n1, m1, a1);
    solve(res, n1, m1, a1, n2, m2, a2);
    flipV(n1, m1, a1);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        mp.clear();
        int n1, m1;
        cin >> n1 >> m1;
        vector<vector<char>> a1(n1, vector<char>(m1, '.'));
        for (int i = 0; i < n1; ++i) {
            for (int j = 0; j < m1; ++j) {
                cin >> a1[i][j];
            }
        }
        int n2, m2;
        cin >> n2 >> m2;
        vector<vector<char>> a2(n2, vector<char>(m2, '.'));
        for (int i = 0; i < n2; ++i) {
            for (int j = 0; j < m2; ++j) {
                cin >> a2[i][j];
            }
        }
        int res = 0;
        solve(res, n1, m1, a1, n2, m2, a2);
        vector<vector<char>> a3(N, vector<char>(N, '.'));
        for (int i = 0; i < n1; ++i) {
            for (int j = 0; j < m1; ++j) {
                a3[i][j] = a1[i][j];
            }
        }
        vector<vector<char>> a4(N, vector<char>(N, '.'));
        for (int i = 0; i < n2; ++i) {
            for (int j = 0; j < m2; ++j) {
                a4[i][j] = a2[i][j];
            }
        }
        n1 = m1 = n2 = m2 = N;
        solve(res, n1, m1, a3, n2, m2, a4);
        cout << res << "\n";
    }
}
