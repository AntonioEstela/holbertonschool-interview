#!/usr/bin/python3
"""
In a text file, there is a single character H.
Your text editor can execute only two operations in this file:
    - Copy All.
    - Paste.

Given a number n, write a method that calculates the fewest
number of operations needed to result in exactly n H characters in the file.
"""


def minOperations(n):
    """
    Method that calculates the fewest number of operations
    needed to result in exactly n H charcacters in the file.
    """

    current = 1
    nOperations = 0
    buffer = 0

    if n < 2:
        return 0

    while current < n:
        rest = n - current

        if rest % current == 0:
            buffer = current
            current += buffer
            nOperations += 2

        else:
            current += buffer
            nOperations += 1

    return nOperations
