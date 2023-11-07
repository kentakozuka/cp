def basex_to_decimal(n: str, base: int = 8) -> int:
    """
    N進数を10進数に変換する
    """
    ret = 0
    x = 1
    for i in reversed(range(len(n))):
        ret += int(n[i]) * x
        x *= base
    return ret


def decimal_to_basex(n: int, base: int = 8) -> int:
    """
    10進数をN進数に変換する
    """
    ret = 0
    x = 1
    while n > 0:
        ret += (n % base) * x
        x *= 10
        n //= base
    return ret
