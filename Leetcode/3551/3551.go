/**
 *    author:  MaGnsi0
 *    created: 17.10.2026 19:51:00
**/
package main

import (
	"fmt"
	"slices"
)

func sumOfdigits(x int) int {
	res := 0
	for i := x; i > 0; i /= 10 {
		res += i % 10
	}
	return res
}

func minSwaps(nums []int) int {
	n := len(nums)
	a := make([][2]int, n)
	for i, x := range nums {
		a[i][0], a[i][1] = x, i
	}
	slices.SortFunc(a, func(x, y [2]int) int {
		sx, sy := sumOfdigits(x[0]), sumOfdigits(y[0])
		if sx < sy {
			return -1
		} else if sx > sy {
			return 1
		} else if x[0] < y[0] {
			return -1
		}
		return 1
	})
	adj := make([][]int, n)
	for i, x := range nums {
		if a[i][0] != x {
			adj[i] = append(adj[i], a[i][1])
		}
	}
	visited := make([]bool, n)
	var dfs func(int) int
	dfs = func(v int) int {
		visited[v] = true
		res := 1
		for _, u := range adj[v] {
			if visited[u] {
				continue
			}
			res += dfs(u)
		}
		return res
	}
	ans := 0
	for i := range n {
		if !visited[i] {
			ans += dfs(i) - 1
		}
	}
	return ans
}

func main() {
	fmt.Println(minSwaps([]int{37, 100}))
	fmt.Println(minSwaps([]int{22, 14, 33, 7}))
	fmt.Println(minSwaps([]int{18, 43, 34, 16}))
	fmt.Println(minSwaps([]int{268835996, 65052660, 415128775}))
}
