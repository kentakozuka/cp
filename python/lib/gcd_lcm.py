# 最大公約数 (greatest common divisor)
def gcd(a, b):
    if b == 0:
        return a
    return gcd(b, a % b)


# 最小公倍数 (least common multiple)
def lcm(a: int, b: int) -> int:
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


a = 10
b = 2

print(gcd(a, b))
print(lcm(a, b))

x = 0
y = 0
print(extgcd(a, b, x, y))
print(x, y)
