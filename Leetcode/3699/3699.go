/**
 *    author:  MaGnsi0
 *    created: 23.06.2026 16:32:06
**/
package main

import "fmt"

func zigZagArrays(n int, l int, r int) int {
	const N, MOD = 2, 1e9 + 7
	M := r - l + 2
	var dp [N][N][]int
	for x := range N {
		for y := range N {
			dp[x][y] = make([]int, M)
		}
	}
	for z := 1; z < M; z++ {
		for x := range N {
			dp[x][0][z] = dp[x][0][z-1] + 1
		}
	}
	for y := 1; y < n; y++ {
		for z := 1; z < M; z++ {
			dp[1][y&1][z] = (dp[0][y&1^1][z-1] + dp[1][y&1][z-1]) % MOD
			dp[0][y&1][z] = (dp[1][y&1^1][M-1] - dp[1][y&1^1][z] + dp[0][y&1][z-1] + MOD) % MOD
		}
	}
	ans := 2 * dp[0][n&1^1][M-1] % MOD
	return ans
}

func main() {
	fmt.Println(zigZagArrays(3, 4, 5))
	fmt.Println(zigZagArrays(3, 1, 3))
	fmt.Println(zigZagArrays(33, 706, 862))
}
