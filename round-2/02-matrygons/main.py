T = int(input())

def find(N):
    if N <= 1:
        return 0
    res = 0
    for d in range(2, N + 1):
        if N % d != 0:
            continue
        res = max(res, find(N // d - 1) + 1)
    return res

for case in range(T):
    N = int(input())
    ans = 0
    for d in range(3, N + 1):
        if N % d != 0:
            continue
        ans = max(ans, find(N // d - 1) + 1)
    print(f"Case #{case + 1}: {ans}")
