# いもす法
# Imos
# verify: https://atcoder.jp/contests/typical90/tasks/typical90_ab

N = int(input())

grid = [[0] * 1001 for _ in range(1001)]
for i in range(N):
    tlx, tly, trx, ttry = map(int, input().split())
    grid[tlx][tly] += 1  # 左下
    grid[trx][tly] += -1  # 右下
    grid[tlx][ttry] += -1  # 左上
    grid[trx][ttry] += 1  # 右上

# x方向
for i in range(1001):
    for j in range(1, 1001):
        grid[j][i] = grid[j - 1][i] + grid[j][i]
for i in range(1001):
    for j in range(1, 1001):
        grid[i][j] = grid[i][j - 1] + grid[i][j]

area = [0] * N
for i in range(1001):
    for j in range(1001):
        if grid[i][j] >= 1:
            area[grid[i][j] - 1] += 1

for i in range(N):
    print(area[i])
