def mod(val: int, mod: int) -> int:
    res = val % mod
    if res < 0:
        res += mod
    return res


def modpow(x: int, n: int, mod: int) -> int:
    res = 1
    while n > 0:
        if n & 1:
            res = res * x % mod
        x = x * x % mod
        n >>= 1
    return res


def modinv(a: int, mod: int) -> int:
    return modpow(a, mod - 2, mod)


def moddiv(a: int, b: int, mod: int) -> int:
    a %= mod
    return (a * modinv(b, mod)) % mod


def modcombi(n: int, k: int, mod: int) -> int:
    ans = 1
    for i in range(n, n - k, -1):
        ans *= i
        ans %= mod
    for i in range(1, k + 1):
        ans *= modinv(i, mod)
        ans %= mod
    return ans
