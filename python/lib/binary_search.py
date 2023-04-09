from typing import List

a: List[int] = [1, 14, 32, 51, 51, 51, 243, 419, 750, 910]


# index が条件を満たすかどうか
# ここを変更する
def isOK(index: int, key: int) -> bool:
    if a[index] >= key:
        return True
    else:
        return False


# めぐる式2分探索
# O(logN)
# 汎用的な二分探索のテンプレ
# https://qiita.com/drken/items/97e37dd6143e33a64c8c
def binary_search(key: int) -> int:
    # 「index = 0」が条件を満たすこともあるので、初期値は -1
    ng: int = -1
    # 「index = a.size()-1」
    # が条件を満たさないこともあるので、初期値は a.size()
    ok: int = len(a)

    # ok と ng のどちらが大きいかわからないことを考慮
    # 大小関係は関係ない。条件を満たすかどうかで変える。
    # 基本は ng < mid < ok を考える
    while abs(ok - ng) > 1:
        mid: int = (ok + ng) // 2
        if isOK(mid, key):
            ok = mid
        else:
            ng = mid
    return ok


# a[3] = 51
# 「最小の index」なので 3)
print(binary_search(51))
# a[0] = 1
print(binary_search(1))
# a[9] = 910
print(binary_search(910))
# 6
print(binary_search(52))
# 0
print(binary_search(0))
# 10 (場外)
print(binary_search(911))
