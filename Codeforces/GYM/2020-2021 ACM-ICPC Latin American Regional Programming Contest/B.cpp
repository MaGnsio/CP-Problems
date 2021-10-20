/**
 *    author:  MaGnsi0
 *    created: 09.10.2021 19:26:12
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int n;
vector<int> a;
vector<vector<int>> divisors(N);
vector<bool> valid(N, true);

void init() {
    a.resize(n);
    for (int i = 1; i < N; ++i) {
        for (int j = 0; j < N; j += i) {
            divisors[j].push_back(i);
        }
    }
}

void mark(int j, int y) {
    for(int i = 0; i < (int)divisors[j].size(); ++i) {
        int x = divisors[j][i];
        if (x >= y) {
            valid[x] = false;
        }
    }
}

void not_valid_partitions() {
    int p = -1, d = -1, state = 0, inv = -1;
    for(int i = 1; i < n; ++i) {
        int pv = d == -1 ? a[i] : a[d];
        if (a[i] == -1 || a[i] == pv) {
            if (state == 0) {
                state = 1;
            } else if (state == 1 || state == 2) {
                state = 2;
            } else if (state == 3) {
                state = 3;
            }
        } else if (a[i] > pv) {
            if (state == 1 || state == 2) {
                state = 1;
            } else {
                state = 4;
            }
        } else if (a[i] < pv) {
            if (state == 0 || state == 4) {
                state = 4;
            } else {
                state = 3;
            }
        }
        if (state != 2 && state != 3) {
            mark(i + 1, i + 1);
        }
        if (a[i] != -1 && a[i - 1] != -1) {
            if (a[i] > a[i - 1]) {
                mark(i + 1, 0);
            } else if (a[i] < a[i - 1]) {
                mark(i - 1, 0);
            }
        }
        if (a[i] != -1) {
            if (d != -1 && a[d] > a[i]) {
                p = d;
            } else if (d != -1 && p != -1 && a[i] > a[d]) {
                inv = p;
            }
            d = i;
        }
        if (inv != -1) {
            mark(i + 1, i - inv + 1);
        }
    }
}

void not_valid_tails() {
    reverse(a.begin(), a.end());
    int p = -1, d = -1, state = 0, inv = -1;
    for(int i = 1; i < n; ++i) {
        int pv = d == -1 ? a[i] : a[d];
        if (a[i] == -1 || a[i] == pv) {
            if (state == 0) {
                state = 1;
            } else if (state == 1 || state == 2) {
                state = 2;
            } else if (state == 3) {
                state = 3;
            }
        } else if (a[i] > pv) {
            if (state == 1 || state == 2) {
                state = 1;
            } else {
                state = 4;
            }
        } else if (a[i] < pv) {
            if (state == 0 || state == 4) {
                state = 4;
            } else {
                state = 3;
            }
        }
        if (state != 2 && state != 3) {
            mark(n - i - 1, i + 1);
        }
        if (a[i] != -1) {
            if (d != -1 && a[d] > a[i]) {
                p = d;
            } else if (d != -1 && p != -1 && a[i] > a[d]) {
                inv = p;
            }
            d = i;
        }
        if (inv != -1) {
            mark(n - i - 1, i + 1);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    init();
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    not_valid_partitions();
    not_valid_tails();
    bool ok = false;
    for (int i = 3; i <= n; ++i) {
        ok |= valid[i];
    }
    cout << (ok ? "Y" : "N");
}
