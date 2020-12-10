#!/usr/bin/python3
"""Method that determines if all the boxes can be opened."""


def canUnlockAll(boxes):
    """Method that determines if all the boxes can be opened."""

    keys = [0]

    if len(boxes) == 0:
        return True

    for i in keys:
        for key in boxes[i]:
            if key not in keys and key < len(boxes):
                keys.append(key)

    return len(keys) == len(boxes)
