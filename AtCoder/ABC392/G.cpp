/**
 *    author:  MaGnsi0
 *    created: 08.02.2025 15:46:09
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 1;

void fft(vector<complex<double>>& a) {
    int n = (int)a.size(), L = 31 - __builtin_clz(n);
    static vector<complex<long double>> R(2, 1);
    static vector<complex<double>> rt(2, 1);
    for (static int k = 2; k < n; k *= 2) {
        R.resize(n); rt.resize(n);
        auto x = polar(1.0L, acos(-1.0L) / k);
        for (int i = k; i < 2 * k; ++i) { rt[i] = R[i] = i & 1 ? R[i / 2] * x : R[i / 2]; }
    }
    vector<int> rev(n);
    for (int i = 0; i < n; ++i) { rev[i] = (rev[i / 2] | (i & 1) << L) / 2; }
    for (int i = 0; i < n; ++i) { if (i < rev[i]) { swap(a[i], a[rev[i]]); } }
    for (int k = 1; k < n; k *= 2) {
        for (int i = 0; i < n; i += 2 * k) {
            for (int j = 0; j < k; ++j) {
                auto x = (double *)&rt[j+k], y = (double *)&a[i+j+k];
                complex<double> z(x[0]*y[0] - x[1]*y[1], x[0]*y[1] + x[1]*y[0]);
                a[i + j + k] = a[i + j] - z;
                a[i + j] += z;
            }
        }
    }
}

vector<double> conv(const vector<double>& a, const vector<double>& b) {
    if (a.empty() || b.empty()) { return {}; }
    vector<double> res((int)a.size() + (int)b.size() - 1);
    int L = 32 - __builtin_clz((int)res.size()), n = 1 << L;
    vector<complex<double>> in(n), out(n);
    copy(a.begin(), a.end(), begin(in));
    for (int i = 0; i < (int)b.size(); ++i) { in[i].imag(b[i]); }
    fft(in);
    for (complex<double>& x : in) { x *= x; }
    for (int i = 0; i < n; ++i) { out[i] = in[-i & (n - 1)] - conj(in[i]); }
    fft(out);
    for (int i = 0; i < (int)res.size(); ++i) { res[i] = imag(out[i]) / (4 * n); }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<double> a(N);
    for (int i = 0; i < n; ++i) {
        int x; cin >> x; a[x] = 1;
    }
    vector<double> b = conv(a, a);
    int64_t ans = 0;
    for (int i = 0; i < N; ++i) {
        if (a[i] == 0) { continue; }
        ans += b[2 * i] / 2;
    }
    cout << ans;
}
