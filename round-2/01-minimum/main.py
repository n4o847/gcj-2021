T, N = map(int, input().split())

for t in range(T):
    lo, hi = 1, N
    while True:
        print(f"M {lo} {hi}")
        i = int(input())
        if lo != i:
            print(f"S {lo} {i}")
            assert int(input()) == 1
        lo += 1
        if lo == N:
            break
    print("D")
    assert int(input()) == 1
