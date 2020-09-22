#!/usr/bin/python3
"""
0x09. UTF-8 Validation
"""


from itertools import takewhile


def to_bs(bytes):
    """
    bytes -> bits
    """
    for byte in bytes:
        n = []
        e = 1 << 8
        while e:
            e >>= 1
            n.append(bool(byte & e))
            yield n


def validUTF8(data):
    """
    check valid UTF-8 encoding.
    """
    bs = to_bs(data)
    for byte in bs:
        if byte[0] == 0:
            continue

        a = sum(takewhile(bool, byte))
        if a <= 1:
            return False
        if a >= 4:
            return False

        for _ in range(a - 1):
            try:
                byte = next(bs)
            except StopIteration:
                return False
            if byte[0:2] != [1, 0]:
                return False
    return True
