T = int(input())

for case in range(T):
  N, A, B = map(int, input().split())
  assert A == 1 and B == 2
  U = list(map(int, input().split()))

  if len(U) == 1:
    U.append(0)

  while len(U) > 2:
    U[-3] += U[-1]
    U[-2] += U[-1]
    U.pop()

  a, b = U
  c = 0
  x, y = 0, 1
  while not (y >= b and x + y >= a + b):
    x, y = y, x + y
    c += 1

  print(f"Case #{case + 1}: {c + 2}")
