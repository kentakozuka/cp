# pow.py


def pow(a: int, n: int) -> int:
    """繰り返し二乗法により、aのn乗を計算する"""
    ret = 1
    while n > 0:
        # n の最下位bitが 1 ならば a^(2^i) をかける
        if n & 1:
            ret *= a
        a *= a
        # n を右シフト
        n >>= 1
    return ret
