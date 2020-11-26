#!/usr/bin/python3
"""
Rain
"""


def rain(walls):
    """
    calculate how much water can be trapped
    @walls: walls
    Return: amount of water which can be trapped
    """
    l, r = 0, len(walls) - 1
    water = 0
    lvl = 0
    while l < r:
        if walls[l] < walls[r]:
            cur_lvl = walls[l]
            l = l + 1
        else:
            cur_lvl = walls[r]
            r = r - 1
        lvl = max(lvl, cur_lvl)
        water += lvl - cur_lvl
    return water
