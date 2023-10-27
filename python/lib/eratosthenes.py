import math


def eratosthenes(N):
    """
    エラトステネスの篩
    Nまでの素数を列挙する.
    O(N*log logN)
    """
    is_prime = [True] * (N + 1)
    P = []
    for i in range(2, N + 1):
        if is_prime[i]:
            for j in range(2 * i, N + 1, i):
                is_prime[j] = False
            P.append(i)
    return P


N = 100
primes = eratosthenes(N)
for p in primes:
    print(p)
