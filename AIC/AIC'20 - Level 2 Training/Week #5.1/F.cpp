//https://vjudge.net/contest/434102#problem/F
#include <bits/stdc++.h>
using namespace std;

void read (int i, int j, int m, vector<vector<int>> &v) {
    if (i < 0) {
        return;
    }
    if (j <= 0) {
        read (i - 1, m, m, v);
    } else {
        read (i, j - 1, m, v);
    }
    cin >> v[i][j];
}

void print (int i, int j, int m, vector<vector<int>> &v) {
    if (i < 0) {
        return;
    }
    if (j <= 0) {
        print (i - 1, m, m, v);
    } else {
        print (i, j - 1, m, v);
    }
    cout << v[i][j] << " ";
    if (j == m) {
        cout << "\n";
    }
}

int get_element (int i, int j, int k, vector<vector<int>> &V1, vector<vector<int>> &V2, vector<vector<int>> &V3) {
    if (k < 0) {
        return 0;
    } else {
        return ((V1[i][k] * V2[k][j]) + get_element (i, j, k - 1, V1, V2, V3));
    }
}

void multiply (int i, int j, int m, int k, vector<vector<int>> &V1, vector<vector<int>> &V2, vector<vector<int>> &V3) {
    if (i < 0) {
        return;
    }
    if (j <= 0) {
        multiply (i - 1, m, m, k, V1, V2, V3);
    } else {
        multiply (i, j - 1, m, k, V1, V2, V3);
    }
    V3[i][j] += get_element (i, j, k - 1, V1, V2, V3);
}

int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int Ra, Ca, Rb, Cb;
    cin >> Ra >> Ca;
    vector<vector<int>> V1 (Ra, vector<int> (Ca));
    read (Ra - 1, Ca - 1, Ca - 1, V1);
    cin >> Rb >> Cb;
    vector<vector<int>> V2 (Rb, vector<int> (Cb));
    read (Rb - 1, Cb - 1, Cb - 1, V2);
    vector<vector<int>> V3 (Ra, vector<int> (Cb, 0));
    multiply (Ra - 1, Cb - 1, Cb - 1, Rb, V1, V2, V3);
    print (Ra - 1, Cb - 1, Cb - 1, V3);
}
