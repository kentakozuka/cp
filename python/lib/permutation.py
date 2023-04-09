import itertools


# 順列（文字列）
# O(n!)
def print_string_permutations(s: str) -> None:
    for p in itertools.permutations(s):
        print("".join(p))


# 順列（数値）
# O(n!)
def print_int_permutations(nums: list[int]) -> None:
    for p in itertools.permutations(nums):
        print(" ".join(map(str, p)))


print_string_permutations("str")
print_int_permutations([1, 2, 3])
