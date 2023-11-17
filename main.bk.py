import sys

sys.setrecursionlimit(10**6)
fn = lambda: int(input())
f = lambda: input().split()
ff = lambda: map(int, input().split())
fff = lambda: list(map(int, input().split()))
from collections import Counter, deque, defaultdict
from itertools import combinations, permutations
import re, math, heapq, bisect
from copy import deepcopy

mod = 10**9 + 7
dis = ((1, 0), (-1, 0), (0, 1), (0, -1))
k10 = [1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800]
