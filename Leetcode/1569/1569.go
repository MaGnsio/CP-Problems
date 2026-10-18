/**
 *    author:  MaGnsi0
 *    created: 19.10.2026 01:54:30
**/
package main

import (
	"fmt"
)

func numOfWays(nums []int) int {
	const MOD int64 = 1e9 + 7
	n := len(nums)

	power := func(b, p int64) int64 {
		res := int64(1)
		for p > 0 {
			if p%2 == 1 {
				res = (res * b) % MOD
			}
			b = b * b % MOD
			p /= 2
		}
		return res
	}

	adj := make([][2]int, n+1)
	func() [][2]int {
		for i := range adj {
			adj[i] = [2]int{-1, -1}
		}
		root := nums[0]
		for i := 1; i < n; i++ {
			curr := root
			val := nums[i]
			for {
				if val < curr {
					if adj[curr][0] == -1 {
						adj[curr][0] = val
						break
					}
					curr = adj[curr][0]
				} else {
					if adj[curr][1] == -1 {
						adj[curr][1] = val
						break
					}
					curr = adj[curr][1]
				}
			}
		}
		return adj
	}()

	F := make([]int64, n+1)
	F[0] = 1
	F[1] = 1
	for i := 2; i <= n; i++ {
		F[i] = F[i-1] * int64(i) % MOD
	}

	S := make([]int64, n+1)
	var dfs func(int) int64
	dfs = func(x int) int64 {
		if adj[x][0] == -1 && adj[x][1] == -1 {
			S[x] = 1
		} else if adj[x][0] == -1 {
			S[x] = dfs(adj[x][1]) + 1
		} else if adj[x][1] == -1 {
			S[x] = dfs(adj[x][0]) + 1
		} else {
			S[x] = dfs(adj[x][0]) + dfs(adj[x][1]) + 1
		}
		return S[x]
	}
	dfs(nums[0])

	var solve func(int) int64
	solve = func(x int) int64 {
		if adj[x][0] == -1 && adj[x][1] == -1 {
			return 1
		}
		if adj[x][0] == -1 {
			return solve(adj[x][1])
		}
		if adj[x][1] == -1 {
			return solve(adj[x][0])
		}
		y, z := adj[x][0], adj[x][1]
		return solve(y) * solve(z) % MOD * F[S[y]+S[z]] % MOD * power(F[S[y]], MOD-2) % MOD * power(F[S[z]], MOD-2) % MOD
	}
	return int((solve(nums[0]) + MOD - 1) % MOD)
}

func main() {
	fmt.Println(numOfWays([]int{2, 1, 3}))
	fmt.Println(numOfWays([]int{3, 4, 5, 1, 2}))
	fmt.Println(numOfWays([]int{1, 2, 3}))
	fmt.Println(numOfWays([]int{3, 1, 2, 5, 4, 6}))
}
