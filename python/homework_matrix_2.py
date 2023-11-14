from utils import Matrix, get_len, get_matrix, get_str, print_matrix

def filter_repeated_integers(arr: list[int]):
  filtered: list[int] = []
  for i in range(len(arr)):
    if arr[i] not in arr[i + 1:]:
      filtered.append(arr[i])
  return filtered

def get_difference(foo: Matrix, bar: Matrix):
  length = len(foo)

  if length != len(bar):
    raise "Cannot perform difference on matrices of different sizes"

  difference: list[int] = []
  checked: list[int] = []

  for i in range(length):
    for j in range(length):
      current_int = foo[i][j]

      if current_int in checked:
        continue

      not_repeated = True
      for row in bar:
        if current_int in row:
          not_repeated = False
          break

      if not_repeated:
        difference.append(current_int)

      checked.append(current_int)
  return difference

print("1. Finding elements in matrix A that are not in matrix B")
length = get_len()
matricina = get_matrix(length, "a")
matricino = get_matrix(length, "a")
difference = get_difference(matricina, matricino)

print("Matrix A:")
print_matrix(matricina)
print("Matrix B:")
print_matrix(matricino)
print("Difference (A - B):")
print(difference)

print("2. Filtering out repeated integers")
matricino = get_matrix(4, get_str("Enter fill mode (a - auto, m - manual)"))
vectorcin = [
  matricino[i][j]
  for i in range(4)
  for j in range(4)
]

print("Befor filtering:")
print(vectorcin)

vectorcin = filter_repeated_integers(vectorcin)

print("After filtering:")
print(vectorcin)
