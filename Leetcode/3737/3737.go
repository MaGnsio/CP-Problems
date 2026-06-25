/**
 *    author:  MaGnsi0
 *    created: 25.06.2026 18:39:30
**/
package main

import "fmt"

type SegmentTree struct {
	n    int
	tree []int
}

func NewSegmentTree(arr []int) *SegmentTree {
	n := len(arr)
	st := &SegmentTree{
		n:    n,
		tree: make([]int, 4*n),
	}
	if n > 0 {
		st.build(arr, 1, 0, n-1)
	}
	return st
}

func (st *SegmentTree) build(arr []int, node, start, end int) {
	if start == end {
		st.tree[node] = arr[start]
		return
	}
	mid := start + (end-start)/2
	leftChild := 2 * node
	rightChild := 2*node + 1
	st.build(arr, leftChild, start, mid)
	st.build(arr, rightChild, mid+1, end)
	st.tree[node] = st.tree[leftChild] + st.tree[rightChild]
}

func (st *SegmentTree) Add(idx int, value int) {
	st.add(1, 0, st.n-1, idx, value)
}

func (st *SegmentTree) add(node, start, end, idx, val int) {
	if start == end {
		st.tree[node] += val
		return
	}
	mid := start + (end-start)/2
	leftChild := 2 * node
	rightChild := 2*node + 1
	if idx <= mid {
		st.add(leftChild, start, mid, idx, val)
	} else {
		st.add(rightChild, mid+1, end, idx, val)
	}
	st.tree[node] = st.tree[leftChild] + st.tree[rightChild]
}

func (st *SegmentTree) Query(L, R int) int {
	return st.query(1, 0, st.n-1, L, R)
}

func (st *SegmentTree) query(node, start, end, L, R int) int {
	if L > R {
		return 0
	}
	if R < start || L > end {
		return 0
	}
	if L <= start && end <= R {
		return st.tree[node]
	}
	mid := start + (end-start)/2
	leftSum := st.query(2*node, start, mid, L, R)
	rightSum := st.query(2*node+1, mid+1, end, L, R)
	return leftSum + rightSum
}

func countMajoritySubarrays(nums []int, target int) int {
	n := len(nums)
	f := make([]int, n+1)
	for i, x := range nums {
		if x == target {
			f[i+1] = 1
		} else {
			f[i+1] = -1
		}
		f[i+1] += f[i]
	}
	for i := range n + 1 {
		f[i] += n
	}
	ans := 0
	s := NewSegmentTree(make([]int, 2*n+1))
	s.Add(f[0], 1)
	for i := 1; i <= n; i++ {
		ans += s.Query(0, f[i]-1)
		s.Add(f[i], 1)
	}
	return ans
}

func main() {
	fmt.Println(countMajoritySubarrays([]int{1, 2, 2, 3}, 2))
	fmt.Println(countMajoritySubarrays([]int{1, 1, 1, 1}, 1))
	fmt.Println(countMajoritySubarrays([]int{1, 2, 3}, 4))
}
