def gcd(a, b):
    """
    最大公約数 (greatest common divisor)
    ユークリッド互除法
    O(log(a + b))
    """
    if b == 0:
        return a
    return gcd(b, a % b)


def lcm(a: int, b: int) -> int:
    """
    最小公倍数 (least common multiple)
    O(log(a + b))
    """
    return a // gcd(a, b) * b


def extgcd(a: int, b: int, x: int, y: int) -> int:
    d = a
    if b != 0:
        d = extgcd(b, a % b, y, x)
        y -= (a // b) * x
    else:
        x = 1
        y = 0
    return d
