# 組み合わせ(combination)を求める
def nCr(n: int, r: int) -> int:
    if r > n:
        return 0
    if r == 0 or n == r:
        return 1
    if r * 2 > n:
        r = n - r

    res = n
    for i in range(2, r + 1):
        res *= n - i + 1
        res //= i
    return res


# 二項係数ライブラリ
class BiCoef:
    def __init__(self, mod: int, max: int):
        self.mod = mod
        self.max = max
        self.fac = [0] * max
        self.finv = [0] * max
        self.inv = [0] * max
        self.fac[0] = self.fac[1] = 1
        self.finv[0] = self.finv[1] = 1
        self.inv[1] = 1
        for i in range(2, max):
            self.fac[i] = self.fac[i - 1] * i % mod
            self.inv[i] = mod - self.inv[mod % i] * (mod // i) % mod
            self.finv[i] = self.finv[i - 1] * self.inv[i] % mod

    # 二項係数計算
    def com(self, n: int, k: int) -> int:
        if n < k:
            return 0
        if n < 0 or k < 0:
            return 0
        return self.fac[n] * (self.finv[k] * self.finv[n - k] % self.mod) % self.mod


# 重複組み合わせを求める
# r個のものをn種類にわける
def nHr(n: int, r: int) -> int:
    return nCr(n + r - 1, r)
