#!/usr/bin/python3
"""Method that determines if all the boxes can be opened."""


def canUnlockAll(boxes):
    """Method that determines if all the boxes can be opened."""

    keys = [0]
    indxBox = 0

    if len(boxes) == 0:
        return True

    for box in boxes:
        if indxBox in keys:
            for key in box:
                if key not in keys:
                    keys.append(key)

        indxBox += 1

    indxBox = 0

    for box in boxes:
        if indxBox in keys:
            for key in box:
                if key not in keys:
                    keys.append(key)

        indxBox += 1

    return len(keys) == len(boxes)
