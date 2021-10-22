//O(n^2) DP Algorithm
template <typename T>
void LIS(vector<T>& A, vector<int>& memo) {
    static int n = A.size();
    for (int i = n - 1; i >= 0; --i) {
        for (int j = 0; j < i; ++j) { 
            if (A[j] < A[i]) {
                memo[i] = max(memo[i], memo[j] + 1);
            }
        }
    }
}

//O(n log k) Greedy + D&C Algorithm
template <typename T>
void LIS(vector<T>& A, vector<int>& memo) {
    int n = A.size(), k = 0;
    vector<T> L(n, 0);
    for (int i = 0; i < n; ++i) {
        int pos = lower_bound(L.begin(), L.begin() + k, A[i]) - L.begin();
        L[pos] = A[i];
        if (pos == k) {
            k++;
        }
        memo[i] = pos + 1;
    }
}

//LIS with output building O(n log k)
template <typename T>
int LIS(vector<T>& A, vector<int>& memo, vector<int>& p) {
    int n = A.size(), k = 0, lis_end = 0;
    vector<T> L(n, 0);
    vector<int> L_id(n, 0);
    p.assign(n, -1);
    for (int i = 0; i < n; ++i) {
        int pos = lower_bound(L.begin(), L.begin() + k, A[i]) - L.begin();
        L[pos] = A[i];
        L_id[pos] = i;
        p[i] = (pos ? L_id[pos - 1] : -1);
        if (pos == k) {
            k = pos + 1;
            lis_end = i;
        }
        memo[i] = pos + 1;
    }
    return lis_end;
}
