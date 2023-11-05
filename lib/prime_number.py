import math
from typing import List, Tuple


def is_prime(x: int) -> bool:
    """
    素数判定
    O(sqrt N)
    """
    if x == 1:
        return False
    for i in range(2, int(math.sqrt(x)) + 1):
        if x % i == 0:
            return False
    return True


def divisors(x: int) -> List[int]:
    """
    約数列挙(未ソート)
    O(sqrt N)
    """
    ret = []
    for i in range(1, int(math.sqrt(x)) + 1):
        if x % i == 0:
            ret.append(i)
            if i != x // i:
                ret.append(x // i)
    return ret


def prime_factorize(N: int) -> List[Tuple[int, int]]:
    """
    素因数分解
    O(sqrt N)
    返却値: List[Tuple[約数, 指数]]
    """
    res = []
    for a in range(2, int(math.sqrt(N)) + 1):
        if N % a != 0:
            continue
        ex = 0
        while N % a == 0:
            ex += 1
            N //= a
        res.append((a, ex))
    if N != 1:
        res.append((N, 1))
    return res
