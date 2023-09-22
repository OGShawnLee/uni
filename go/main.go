package main

import "fmt"

func capitalize(s string) string {
	if len(s) < 1 {
		return s
	}
	return string(s[0]-32) + s[1:]
}

func getFloat(prompt string) float32 {
	var f float32
	fmt.Print(prompt + ": ")
	fmt.Scanln(&f)
	return f
}

func getString(prompt string) string {
	var s string
	fmt.Print(prompt + ": ")
	fmt.Scanln(&s)
	return s
}

func getUInt(prompt string) uint {
	var i uint
	fmt.Print(prompt + ": ")
	fmt.Scanln(&i)
	return i
}

func getInt(prompt string) int {
	var i int
	fmt.Print(prompt + ": ")
	fmt.Scanln(&i)
	return i
}

func isInRange(i, min, max int) bool {
	return i >= min && i <= max
}

func isOutsideRange(i, min, max int) bool {
	return i < min || i > max
}

func runFourthTask() {
	age := getInt("What is your age?")

	if isOutsideRange(age, 0, 130) {
		fmt.Println("Your age must be between 0 and 130")
	} else {
		if isInRange(age, 18, 25) {
			fmt.Println("You are in the range 18-25")
		} else if isInRange(age, 50, 55) {
			fmt.Println("You are in the range 26-35")
		} else {
			fmt.Println("You are not in the allowed age ranges")
		}
	}

	rating := getInt("What was your rating?")

	if isOutsideRange(rating, 0, 10) {
		fmt.Println("Your rating must be between 0 and 10")
	} else {
		if rating == 9 || rating == 10 {
			fmt.Println("Notable")
		} else if rating == 8 {
			fmt.Println("Aproved")
		} else if rating == 7 || rating == 6 {
			fmt.Println("Good")
		} else {
			fmt.Println("You must study more!")
		}
	}

	x := getInt("Enter a value for x?")
	y := getInt("Enter a value for y?")

	if x == 0 || y == 0 {
		fmt.Println("x and y must be different from 0")
	} else {
		fmt.Printf("2 + (3 * %d) = %d\n", x, 2+(3*x))
		fmt.Printf("2 + (3 * %d) = %d\n", y, 2+(3*y))
	}

	a := getInt("Enter a number for a")
	b := getInt("Enter a number for b")
	c := getInt("Enter a number for c")

	if a == b && b == c {
		fmt.Println("Ordered the same")
	} else if a >= b && b >= c {
		fmt.Println("Descending Order")
	} else if a <= b && b <= c {
		fmt.Println("Ascending Order")
	} else {
		fmt.Println("Unordered")
	}
}

func runFirstTask() {
	name := getString("What is your name?")
	age := getUInt("What is your age?")
	height := getFloat("What is your height in meters?")
	gender := getString("What is your gender? (M/F)")
	crime := getString("What was your crime?")

	name = capitalize(name)
	gender = capitalize(gender)
	crime = capitalize(crime)

	println("Prisoner Details")
	println("Name:", name)
	println("Age:", age)
	println("Height:", height)
	println("Gender:", gender)
	println("Crime:", crime)
}

func main() {
	// runFirstTask()
	runFourthTask()
}
