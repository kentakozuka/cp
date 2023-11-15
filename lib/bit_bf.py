from itertools import product

n = 3

# bit全探索
# O(N*2^N)
# N個のものから、いくつか選ぶ方法を全列挙して調べ上げる手法
# (1<<N)は2^Nの意味
for p in product((0, 1), repeat=n):
    for i in range(n):
        if p[i]:
            print(i, end=" ")
    print("")

for bit in range(1 << n):
    S = []
    for i in range(n):
        # 列挙に i が含まれるか
        # (1<<i): i桁目のみが1で他は0であるようなビット列である
        # &は論理積:
        if bit & (1 << i):
            S.append(i)
    for i in range(len(S)):
        print(S[i], end=" ")
    print("")
