/**
 *    author:  MaGnsi0
 *    created: 02.06.2024 15:57:00
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int operations = 0;
    int n; cin >> n;
    vector<int> a(n);
    iota(a.begin(), a.end(), 1);
    function<int(int, int)> ask = [&](int i, int j) {
        assert(operations++ <= 25000);
        cout << "? " << i << " " << j << endl;
        int x; cin >> x; return x;
    };
    function<int(int, int)> add = [&](int i, int j) {
        assert(operations++ <= 25000);
        cout << "+ " << i << " " << j << endl;
        int x; cin >> x; return x;
    };
    function<void(int, int, int)> merge = [&](int low, int mid, int high) {
        int n1 = mid - low + 1, n2 = high - mid;
        vector<int> a1(n1), a2(n2);
        for (int i = 0; i < n1; ++i) {
            a1[i] = a[low + i];
        }
        for (int i = 0; i < n2; ++i) {
            a2[i] = a[mid + i + 1];
        }
        int j = low, j1 = 0, j2 = 0;
        while (j1 < n1 && j2 < n2) {
            if (ask(a1[j1], a2[j2])) {
                a[j++] = a1[j1++];
            } else {
                a[j++] = a2[j2++];
            }
        }
        while (j1 < n1) { a[j++] = a1[j1++]; }
        while (j2 < n2) { a[j++] = a2[j2++]; }
    };
    function<void(int, int)> merge_sort = [&](int low, int high) {
        if (low >= high) { return; }
        int mid = (low + high) / 2;
        merge_sort(low, mid);
        merge_sort(mid + 1, high);
        merge(low, mid, high);
    };
    merge_sort(0, n - 1);
    while (n > 1) {
        vector<int> b;
        int x = add(a[0], a[n - 1]);
        int low = 1, high = n - 2, j = -1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (ask(x, a[mid])) {
                j = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        for (int i = 1; i + 1 < n; ++i) {
            if (i == j) { b.push_back(x); }
            b.push_back(a[i]);
        }
        if (j == -1) { b.push_back(x); }
        n--, a = b;
    }
    cout << "!" << endl;
}
