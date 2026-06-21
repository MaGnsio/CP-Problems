/**
 *    author:  MaGnsi0
 *    created: 21.06.2026 23:01:38
**/
package main

import (
	"fmt"
	"slices"
)

func maxIceCream(costs []int, coins int) int {
	slices.Sort(costs)
	for j, x := range costs {
		if coins < x {
			return j
		}
		coins -= x
	}
	return len(costs)
}

func main() {
	fmt.Println(maxIceCream([]int{1, 3, 2, 4, 1}, 7))
	fmt.Println(maxIceCream([]int{10, 6, 8, 7, 7, 8}, 5))
	fmt.Println(maxIceCream([]int{1, 6, 3, 1, 2, 5}, 20))
}
