/**
 *    author:  MaGnsi0
 *    created: 13.10.2026 21:56:00
**/
package main

import (
	"fmt"
)

const N = 40001

var F [N]uint

func maxAlternatingSum(nums []int) int64 {
	ans, remove := int64(0), len(nums)/2
	for _, x := range nums {
		F[max(x, -x)]++
		ans += int64(x * x)
	}
	for x, y := range F {
		if remove == 0 {
			break
		}
		to_remove := min(int(y), remove)
		ans -= int64(2 * to_remove * x * x)
		remove -= to_remove
	}
	clear(F[0:N])
	return ans
}

func main() {
	fmt.Println(maxAlternatingSum([]int{1, 2, 3}))
	fmt.Println(maxAlternatingSum([]int{1, -1, 2, -2, 3, -3}))
}

