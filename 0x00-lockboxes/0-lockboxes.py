#!/usr/bin/python3
"""
canUnlockAll module
"""

open_pos = [0]
status = False
boxes_g = []


def canUnlockAll(boxes):
    """
    open a box of boxes
    """
    global status
    global open_pos
    global l
    global pos
    global boxes_g

    if type(boxes) is not list:
        return False

    boxes_g = boxes
    open_pos = [0]
    status = False
    l = len(boxes_g)

    if l == 0:
        return False
    if l == 1:
        return True

    pos = list(range(0, l))
    first_box = boxes[0]

    openBox(first_box)
    return status


def openBox(box):
    """
    open a box
    """
    global status
    global open_pos
    global l
    global pos
    global boxes_g
    if type(box) is not list:
        status = False
        return False
    for v in box:
        if isinstance(v, int):
            if v <= l-1:
                if v not in open_pos:
                    open_pos.append(v)
                    if set(open_pos) == set(pos):
                        status = True
                        return True
                    openBox(boxes_g[v])
