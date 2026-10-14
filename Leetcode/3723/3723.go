/**
 *    author:  MaGnsi0
 *    created: 15.10.2026 01:02:00
**/
package main

import (
	"fmt"
	"strconv"
	"strings"
)

func maxSumOfSquares(num int, sum int) string {
	if 9 * num < sum {
		return ""
	}
	nines := sum / 9
	ans := strings.Repeat("9", nines)
	num -= nines
	if sum % 9 != 0 {
		ans = ans + strconv.Itoa(sum % 9)
		num--
	}
	ans = ans + strings.Repeat("0", num)
	return ans
}

func main() {
	fmt.Println(maxSumOfSquares(2, 3))
	fmt.Println(maxSumOfSquares(2, 17))
	fmt.Println(maxSumOfSquares(1, 10))
}
