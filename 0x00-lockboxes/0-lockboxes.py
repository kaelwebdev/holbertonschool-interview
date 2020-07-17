"""
canUnlockAll module
"""

open_pos = [0]
status = False


def canUnlockAll(boxes):
    """
    open a box of boxes
    """
    global status
    global open_pos
    global l
    global pos
    open_pos = [0]
    status = False
    l = len(boxes)
    pos = list(range(0, l))
    first_box = boxes[0]
    for idx, box in enumerate(boxes):
        for v in box:
            if v < l-1:
                if v not in open_pos:
                    open_pos.append(v)
                    openBox(boxes[v], boxes)
                if status is True:
                    return True
        if status is True:
            return True
        else:
            return False
    return status


def openBox(box, boxes):
    """
    open a box
    """
    global status
    global open_pos
    global l
    global pos
    if set(open_pos) == set(pos):
        status = True
        return True
    for idx, v in enumerate(box):
        if v <= l-1:
            if v not in open_pos:
                open_pos.append(v)
                openBox(boxes[v], boxes)