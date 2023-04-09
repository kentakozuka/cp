from collections import defaultdict

Map = defaultdict(int)
N, K = map(int, input().split())
A = list(map(int, input().split()))
ans = 0
cnt = 0

def add(right):
    global cnt
    Map[A[right]] += 1
    if Map[A[right]] == 1:
        cnt += 1

def remove(left):
    global cnt
    Map[A[left]] -= 1
    if Map[A[left]] == 0:
        cnt -= 1

def is_ok(left, right):
    global ans, cnt
    if cnt <= K:
        ans = max(ans, right - left + 1)
        return True
    else:
        return False

def two_pointer():
    global ans
    n = len(A)
    right = -1
    for left in range(n):
        while right < n:
            if left <= right and not is_ok(left, right):
                break
            right += 1
            add(right)
        remove(left)

two_pointer()

print(ans)
