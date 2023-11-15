def pivot(a: list[int], i: int, j: int) -> int:
    k = i + 1
    while k <= j and a[i] == a[k]:
        k += 1
    if k > j:
        return -1
    if a[i] >= a[k]:
        return i
    return k


def partition(a: list[int], left: int, right: int, x: int) -> int:
    l = left
    r = right
    while l <= r:
        while l <= right and a[l] < x:
            l += 1
        while r >= left and a[r] >= x:
            r -= 1
        if l > r:
            break
        a[l], a[r] = a[r], a[l]
        l += 1
        r -= 1
    return l


def quick_sort(a: list[int], left: int, right: int) -> None:
    if left == right:
        return
    p = pivot(a, left, right)
    if p != -1:
        k = partition(a, left, right, a[p])
        quick_sort(a, left, k - 1)
        quick_sort(a, k, right)


def selection_sort(a: list[int]) -> None:
    for i in range(len(a) - 1):
        m = i
        for j in range(i + 1, len(a)):
            if a[j] < a[m]:
                m = j
        a[i], a[m] = a[m], a[i]


def bubble_sort(a: list[int]) -> None:
    for i in range(len(a) - 1):
        for j in range(len(a) - 1, i, -1):
            if a[j] < a[j - 1]:
                a[j], a[j - 1] = a[j - 1], a[j]


def insertion_sort(a: list[int]) -> None:
    for i in range(1, len(a)):
        k = a[i]
        j = i - 1
        while j >= 0 and a[j] > k:
            a[j + 1] = a[j]
            j -= 1
        a[j + 1] = k


def merge(a: list[int], left: int, mid: int, right: int) -> None:
    L = a[left : mid + 1]
    R = a[mid + 1 : right + 1]
    L.append(float("inf"))
    R.append(float("inf"))
    l = r = 0
    for i in range(left, right + 1):
        if L[l] <= R[r]:
            a[i] = L[l]
            l += 1
        else:
            a[i] = R[r]
            r += 1


def merge_sort(a: list[int], left: int, right: int) -> None:
    if left < right:
        mid = (left + right) // 2
        merge_sort(a, left, mid)
        merge_sort(a, mid + 1, right)
        merge(a, left, mid, right)


if __name__ == "__main__":
    v = [3, 2, 0, 5, 8, 3, 4, 1, 3, 2]

    a = v.copy()
    quick_sort(a, 0, len(a) - 1)
    print(a)

    a = v.copy()
    selection_sort
