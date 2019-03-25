package main

import (
	"fmt"
	"math"
)
func main() {
	var t, n int
	fmt.Scanf("%d\n%d\n", &t, &n)
	for t; t>0; t-- {
		fmt.Scanf("%d", &n)
		pos, neg := 0,0
		for n; n > 0; n-- {
			var temp int;
			fmt.Scanf("%d", &temp)
			if temp > 0 {
				pos++
			} else {neg++}
		}
		if pos*neg == 0 {
			fmt.Printf("%d %d\n", pos+neg, pos+neg)
		} else {
			fmt.Printf("%d %d\n", math.Max(pos, neg), math.Min(pos, neg))
		}
	}
} 
