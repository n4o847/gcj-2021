from itertools import permutations

T = int(input())

Z = 360 * 12 * 10**10

for case in range(T):
  A, B, C = map(int, input().split())

  cand = []
  for a, b, c in permutations([A, B, C]):
    t11 = (b - a) % Z
    found = [(t11 + i * Z) // 11 for i in range(11) if (t11 + i * Z) % 11 == 0]
    if len(found) != 1:
      continue
    t = found[0]
    o = (a - t) % Z
    if (o + 720 * t) % Z == c:
      if o == 0:
        cand.insert(0, t)
      else:
        cand.append(t)

  ans = cand[0]

  if cand:
    ans = cand[0]
    n = ans % (10 ** 9)
    s = ans // (10 ** 9) % 60
    m = ans // (10 ** 9) // 60 % 60
    h = ans // (10 ** 9) // 60 // 60
    print(f"Case #{case + 1}: {h} {m} {s} {n}")
  else:
    exit(1)
