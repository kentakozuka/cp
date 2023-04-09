n = 3

# bit全探索
# N個のものから、いくつか選ぶ方法を全列挙して調べ上げる手法
# O(N*2^N)
# (1<<N)は2^Nの意味
for bit in range(1 << n):
    S = []
    for i in range(n):
        # 列挙に i が含まれるか
        # (1<<i): i桁目のみが1で他は0であるようなビット列である
        # &は論理積:
        if bit & (1 << i):
            S.append(i)
    print(bit, ": {", end="")
    for i in range(len(S)):
        print(S[i], end=" ")
    print("}")
