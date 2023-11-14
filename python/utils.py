from random import randint
from typing import Literal, List

Matrix = List[List[int]]
MAX_LEN = 15

def get_int(prompt: str) -> int:
    return int(input(f"{prompt}: "))

def get_float(prompt: str) -> float:
    return float(input(f"{prompt}: "))

def get_len(message = "Enter length of matrix"):
  len = int(input(f"{message}: "))
  if len > MAX_LEN:
    print(f"Length is too big. Length has been truncated to {MAX_LEN}")
    len = MAX_LEN
  return len

def get_str(prompt: str) -> str:
    return input(f"{prompt}: ")

def report_value(name: str, value):
    print(f"{name}: {value}")

def is_in_range(value, lower, upper):
    return value >= lower and value <= upper

def is_outside_range(value, lower, upper):
    return value < lower or value > upper

def print_matrix(matrix: Matrix):
  for row in matrix:
    print(row)

def get_matrix(length: int, fill_mode: Literal["m", "a"]) -> Matrix:
  if fill_mode == "a":
    return [
      [randint(0, 9) for col in range(length)]
      for row in range(length)
    ]
  elif fill_mode == "m":
    return [
      [get_int(f"Enter integer for position ({row}, {col})") for col in range(length)]
      for row in range(length)
    ]
  else:
    print("Invalid fill mode")
    return get_matrix(length, input("Enter fill mode (a - automatic, m - manual): "))