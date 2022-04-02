T = int(input())
M = 10 ** 9 + 7

for case in range(T):
    N = int(input())
    V = list(map(int, input().split()))
    dp = [0] * (1 << N)
    dp[0] = 1
    for s in range(1 << N):
        cnt = 0
        for i in range(N):
            if s & (1 << i):
                cnt += 1
        V[cnt]
        for i in range(N):
            if s & (1 << i):
                continue
            dp[s | (1 << i)] += dp[s]
    P = []
    ans = 1
    for i in range(N):
        if i == 0:
            P.append(1)
        elif V[i - 1] + 1 < V[i]:
            ans = 0
            break
        elif V[i - 1] + 1 == V[i]:
            ans *= (sum(P) - len(P))
            ans *= (i + 1) - V[i] + 1
        else V[i - 1] >= V[i]:
            s = 0
            for _ in range(V[i - 1] - V[i]):
                s += P.pop()
    print(f"Case #{case + 1}: {ans}")
