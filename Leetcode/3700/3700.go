/**
 *    author:  MaGnsi0
 *    created: 24.06.2026 21:28:32
**/
package main

import "fmt"

const MOD = 1e9 + 7

type Matrix [][]int64

func mul(a, b Matrix) Matrix {
	n := len(a)
	m := len(b[0])
	res := make(Matrix, n)
	for i := range res {
		res[i] = make([]int64, m)
	}

	for i := range n {
		for k := 0; k < len(a[0]); k++ {
			r := a[i][k]
			if r == 0 {
				continue
			}
			for j := range m {
				res[i][j] = (res[i][j] + r*b[k][j]) % MOD
			}
		}
	}
	return res
}

func powMul(base Matrix, exp int64, res Matrix) Matrix {
	for exp > 0 {
		if exp&1 == 1 {
			res = mul(res, base)
		}
		base = mul(base, base)
		exp >>= 1
	}
	return res
}

func zigZagArrays(n int, l int, r int) int {
	m := r - l + 1
	t := make(Matrix, 2*m)
	for i := range 2 * m {
		t[i] = make([]int64, 2*m)
	}
	for i := range m {
		for j := range i {
			t[i][j+m] = 1
		}
		for j := i + 1; j < m; j++ {
			t[i+m][j] = 1
		}
	}
	dp := make(Matrix, 1)
	dp[0] = make([]int64, 2*m)
	for i := 0; i < 2*m; i++ {
		dp[0][i] = 1
	}
	dp = powMul(t, int64(n-1), dp)
	var ans int64 = 0
	for i := 0; i < 2*m; i++ {
		ans = (ans + dp[0][i]) % MOD
	}
	return int(ans)
}

func main() {
	fmt.Println(zigZagArrays(3, 4, 10))
}
