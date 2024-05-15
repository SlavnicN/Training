package main

import "fmt"

func containsDuplicate(num []int) bool {
    var lenght = len(num) //O(1)<O(n)
    var res map[int]int
    res = make(map[int]int)

    for i := 0; i < lenght; i++ {//O(n)
        res[num[i]] = 0
    }

    for i := 0; i < lenght; i++ {//O(n)
        res[num[i]] +=1
        if(res[num[i]] >1){
            return true
        }
    }

	return false
}

func n2_containsDuplicate(num []int) bool {
    var lenght = len(num) //O(1)<O(n)
    for i := 0; i < lenght; i++ {//O(n)
        for j := i+1; j < lenght; j++ {//O(n^2)
            if num[i] == num[j] {//O(1)
                return true
            }
        }
    }
	return false
}
//i=0: j: 1, 2, 3, 4
//i=1: j: 2, 3, 4 ,5
//i=2: j: 
//
//2 -> 4


func main() {
	num := []int{2,14,18,22,22}
	fmt.Println(containsDuplicate(num))
	fmt.Println("Hello, world.")
}
