# https://atcoder.jp/contests/dp/tasks/dp_d

s = input()
t = input()

dp = [[9999 for _ in range(len(t))] for _ in range(len(s))]

for i in range(len(t)):
    dp[0][i] = 0
for i in range(len(s)):
    dp[i][0] = 0
