# https://atcoder.jp/contests/dp/tasks/dp_a

n = int(input())
h = list(map(int, input().split()))

dp = [999999 for _ in range(n)]
dp[0] = 0
dp[1] = abs(h[0] - h[1])

for i in range(n - 2):
    dp[i + 2] = min(dp[i] + abs(h[i] - h[i + 2]), dp[i + 1] + abs(h[i + 1] - h[i + 2]))

# print(dp)
print(dp[-1])
