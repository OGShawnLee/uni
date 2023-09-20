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
	runFirstTask()
}
