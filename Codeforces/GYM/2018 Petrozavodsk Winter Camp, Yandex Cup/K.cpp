/**
 *    author:  MaGnsi0
 *    created: 25.04.2023 21:23:32
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<int> X(n - 1), Y(n - 1);
    for (int i = 0; i < n - 1; ++i) {
        cin >> X[i] >> Y[i];
        X[i]--, Y[i]--;
    }
    vector<int> b(n);
    for (int i = 0; i < n - 1; ++i) {
        b[X[i]]++, b[Y[i]]++;
    }
    int64_t xor_sum = n;
    vector<int> c;
    for (int i = 0; i < n; ++i) {
        if ((b[i] & 1) && (a[i] == 0)) {
            xor_sum ^= (i + 1);
        }
        if ((b[i] & 1) && (a[i] == 1)) {
            if (c.size() < 3) {
                c.push_back(i);
            } else {
                xor_sum ^= (i + 1);
            }
        }
    }
    int k = (int)c.size();
    if (xor_sum == 0) {
        if (k == 0) {
            vector<int64_t> label(n);
            iota(label.begin(), label.end(), 1);
            cout << n << "\n";
            for (int i = 0; i < n - 1; ++i) {
                cout << label[X[i]] << " " << label[Y[i]] << "\n";
            }
        } else if (k == 1) {
            cout << -1;
        } else if (k == 2) {
            cout << -1;
        } else {
            vector<int64_t> label(n);
            iota(label.begin(), label.end(), 1);
            label[c[0]] = (1LL << 26) + (1LL << 27);
            label[c[1]] = (1LL << 26) + (1LL << 28);
            label[c[2]] = (1LL << 27) + (1LL << 28);
            cout << n << "\n";
            for (int i = 0; i < n - 1; ++i) {
                cout << label[X[i]] << " " << label[Y[i]] << "\n";
            }
        }
    } else if (xor_sum <= n) {
        if (k == 0) {
            cout << -1;
        } else if (k == 1) {
            if (xor_sum == c[0] + 1) {
                vector<int64_t> label(n);
                iota(label.begin(), label.end(), 1);
                cout << n << "\n";
                for (int i = 0; i < n - 1; ++i) {
                    cout << label[X[i]] << " " << label[Y[i]] << "\n";
                }
            } else if ((b[xor_sum - 1] % 2 == 0) && (a[xor_sum - 1] == 1)) {
                vector<int64_t> label(n);
                iota(label.begin(), label.end(), 1);
                swap(label[xor_sum - 1], label[c[0]]);
                cout << n << "\n";
                for (int i = 0; i < n - 1; ++i) {
                    cout << label[X[i]] << " " << label[Y[i]] << "\n";
                }
            } else {
                cout << -1;
            }
        } else if (k == 2) {
            vector<int64_t> label(n);
            iota(label.begin(), label.end(), 1);
            label[c[0]] = (1LL << 28);
            label[c[1]] = (1LL << 28) + xor_sum;
            cout << n << "\n";
            for (int i = 0; i < n - 1; ++i) {
                cout << label[X[i]] << " " << label[Y[i]] << "\n";
            }
        } else {
            vector<int64_t> label(n);
            iota(label.begin(), label.end(), 1);
            label[c[0]] = (1LL << 26) + (1LL << 27);
            label[c[1]] = (1LL << 26) + (1LL << 28);
            label[c[2]] = (1LL << 27) + (1LL << 28) + xor_sum;
            cout << n << "\n";
            for (int i = 0; i < n - 1; ++i) {
                cout << label[X[i]] << " " << label[Y[i]] << "\n";
            }
        }
    } else {
        if (k == 0) {
            cout << -1;
        } else if (k == 1) {
            vector<int64_t> label(n);
            iota(label.begin(), label.end(), 1);
            label[c[0]] = xor_sum;
            cout << n << "\n";
            for (int i = 0; i < n - 1; ++i) {
                cout << label[X[i]] << " " << label[Y[i]] << "\n";
            }
        } else if (k == 2) {
            vector<int64_t> label(n);
            iota(label.begin(), label.end(), 1);
            label[c[0]] = (1LL << 28);
            label[c[1]] = (1LL << 28) + xor_sum;
            cout << n << "\n";
            for (int i = 0; i < n - 1; ++i) {
                cout << label[X[i]] << " " << label[Y[i]] << "\n";
            }
        } else {
            vector<int64_t> label(n);
            iota(label.begin(), label.end(), 1);
            label[c[0]] = (1LL << 26) + (1LL << 27);
            label[c[1]] = (1LL << 26) + (1LL << 28);
            label[c[2]] = (1LL << 27) + (1LL << 28) + xor_sum;
            cout << n << "\n";
            for (int i = 0; i < n - 1; ++i) {
                cout << label[X[i]] << " " << label[Y[i]] << "\n";
            }
        }
    }
}
