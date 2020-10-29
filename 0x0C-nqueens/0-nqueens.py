#!/usr/bin/python3
"""
    N queens problem
"""
import sys


def check_pos(s, pos):
    for q in s:
        if q[1] == pos[1]:
            return False
        if (q[0] + q[1]) == (pos[0] + pos[1]):
            return False
        if (q[0] - q[1]) == (pos[0] - pos[1]):
            return False
    return True


def mv_q(r, n, s):
    if (r == n):
        print(s)
    else:
        for col in range(n):
            pos = [r, col]
            if check_pos(s, pos):
                s.append(pos)
                mv_q(r + 1, n, s)
                s.remove(pos)


if __name__ == "__main__":
    if len(sys.argv) != 2:
        print('Usage: nqueens N')
        exit(1)
    try:
        n = int(sys.argv[1])
    except BaseException:
        print('N must be a number')
        exit(1)
    if n < 4:
        print('N must be at least 4')
        exit(1)

    s = []

    mv_q(0, n, s)
