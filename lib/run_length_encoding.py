# ランレングス圧縮
def rl_encode(s: str) -> list[tuple[str, int]]:
    n = len(s)
    ret = []
    i = 0
    while i < n:
        # Count occurrences of current character
        cnt = 1
        while i < n - 1 and s[i] == s[i + 1]:
            cnt += 1
            i += 1
        ret.append((s[i], cnt))
        i += 1
    return ret


# ランレングス圧縮の復元を行う
def decode(code: list[tuple[str, int]]) -> str:
    ret = ""
    for p in code:
        for i in range(p[1]):
            ret += p[0]
    return ret


if __name__ == "__main__":
    s = "tfffffdyyyeeehfj110000"
    print(s)
    e = rl_encode(s)
    for i in range(len(e)):
        print(f"{e[i][1]}{e[i][0]}", end="")
    print()
