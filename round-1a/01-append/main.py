T = int(input())

for t in range(T):
  N = int(input())
  X = input().split()
  prev = ""
  ans = 0
  for x in X:
    if len(prev) < len(x):
      prev = x
      continue
    elif len(prev) == len(x):
      if int(prev) < int(x):
        prev = x
        continue
      else:
        prev = x + "0"
        ans += 1
        continue
    else:
      y = prev[0 : len(x)]
      if y > x:
        add = len(prev) - len(x) + 1
        ans += add
        prev = x + "0" * add
        continue
      elif y < x:
        add = len(prev) - len(x)
        ans += add
        prev = x + "0" * add
        continue
      else:
        prev_inc = str(int(prev) + 1)
        if x == prev_inc[0 : len(x)]:
          add = len(prev) - len(x)
          ans += add
          prev = prev_inc
          continue
        else:
          add = len(prev) - len(x) + 1
          ans += add
          prev = x + "0" * add
          continue
  print(f"Case #{t + 1}: {ans}")
