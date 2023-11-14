from utils import Matrix, get_int, get_len, get_matrix, print_matrix

def find_positions_in_matrix(matrix: Matrix, target: int):
  indices: list[tuple[int, int]] = []
  for row in range(len(matrix)):
    for col in range(len(matrix[row])):
      if matrix[row][col] == target:
        indices.append((row, col))
  return indices

def get_matrix_adition(m_1: Matrix, m_2: Matrix):
  length = len(m_1)
  
  if length != len(m_2):
    print("Cannot perform addition on matrices of different sizes")
    return
  
  return [
    [m_1[row][col] + m_2[row][col] for col in range(length)]
    for row in range(length)
  ]

print("1. Filling matrix manually")
length = get_len()
matricina = get_matrix(length, "m")
print("Matrix A:")
print_matrix(matricina)

print("2. Finding integer in matrix")
target = get_int("Enter integer to find")
positions = find_positions_in_matrix(matricina, target)
for (row, col) in positions:
  print(f"{target} found at position ({row}, {col})")

print("3. Filling matrix with random integers")
matricino = get_matrix(length, "a")
print("Matrix B:")
print_matrix(matricino)

print("4. Performing matrix addition with previous matrices")
matricijo = get_matrix_adition(matricina, matricino)
print("Matrix C (A + B):")
print_matrix(matricijo)