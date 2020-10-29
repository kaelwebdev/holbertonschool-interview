#!/usr/bin/python3
"""
    N queens problem
"""
import sys
from copy import deepcopy


def check_valid(b, r):
    for i in range(r):
        d = abs(b[i][1] - b[r][1])
        if d == 0 or d == r - i:
            return False
    return True


def n_queens(res, b, r, n):
    if r == n:
        res.append(deepcopy(b))
    else:
        for col in range(n):
            b[r][1] = col
            if check_valid(b, r):
                n_queens(res, b, r + 1, n)


if __name__ == '__main__':
    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        exit(1)
    try:
        n = int(sys.argv[1])
    except Exception:
        print("N must be a number")
        exit(1)
    if n < 4:
        print("N must be at least 4")
        exit(1)
    res = []
    b = [[i, -1] for i in range(n)]
    n_queens(res, b, 0, n)
    for i in res:
        print(i)
