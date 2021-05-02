//https://vjudge.net/contest/434102#problem/D
#include <bits/stdc++.h>
using namespace std;

void merge (vector<int> &v, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; ++i) {
        L[i] = v[l + i];
    }
    for (int i = 0; i < n2; ++i) {
        R[i] = v[m + 1 + i];
    }
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            v[k] = L[i];
            i++;
        }
        else {
            v[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        v[k++] = L[i++];
    }
    while (j < n2) {
        v[k++] = R[j++];
    }
}

void mergeSort (vector<int> &v, int l, int r) {
    if (l >= r) {
        return;
    }
    int m = (l + r) / 2;
    mergeSort (v, l, m);
    mergeSort (v, m + 1, r);
    merge (v, l, m, r);
}


int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto& x : v) {
        cin >> x;
    }
    mergeSort (v, 0, n - 1);
    for (auto& x : v) {
        cout << x << " ";
    }
}

