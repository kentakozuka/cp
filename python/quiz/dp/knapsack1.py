# https://atcoder.jp/contests/dp/tasks/dp_d

n, w = map(int, input().split())
wgts, vals = [0 for _ in range(n)], [0 for _ in range(n)]
for i in range(n):
    wgts[i], vals[i] = map(int, input().split())

dp = [[-1 for _ in range(w + 1)] for _ in range(n + 1)]

for i in range(w + 1):
    dp[0][i] = 0

for i in range(n):
    for j in range(w + 1):
        if wgts[i] <= j:
            dp[i + 1][j] = max(dp[i][j - wgts[i]] + vals[i], dp[i][j])
        else:
            dp[i + 1][j] = dp[i][j]

# print(dp)
print(dp[-1][-1])
