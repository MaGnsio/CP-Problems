#include <bits/stdc++.h>

using namespace std;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

int64_t get_random(int64_t l, int64_t r) {
    return uniform_int_distribution<int64_t>(l, r)(rng);
}

void gen() {
    ofstream cout("in.in");
    int T = 1;
    cout << T << endl;
    while (T--) {
        int n = get_random(3, 7);
        cout << n << endl;
        for (int i = 0; i < n; ++i) {
            cout << get_random(1, 10) << " ";
        }
    }
    cout << endl;
}

int main() {
    int T = 0;
    system("g++ ac.cpp -o ac");
    system("g++ wa.cpp -o wa");
    while (++T) {
        gen();
        cerr << T << endl;
        system("ac.exe < in.in > ac.out");
        system("wa.exe < in.in > wa.out");
        ifstream acs("ac.out");
        ifstream was("wa.out");
        string ac, wa;
        getline(acs, ac, (char)EOF);
        getline(was, wa, (char)EOF);
        if (wa != ac) {
            break;
        }
    }
}
