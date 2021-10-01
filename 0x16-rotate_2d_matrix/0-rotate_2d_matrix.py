#!/usr/bin/python3
"""
rotate it 90 degrees clockwise.
"""


def rotate_2d_matrix(matrix):
    """
    Given an n x n 2D matrix
    The matrix must be edited in-place.
    the matrix will have 2 dimensions and will not be empty.
    """
    n = len(matrix)
    for i in range(int(n / 2)):
        y = (n - i - 1)
        for j in range(i, y):
            x = (n - 1 - j)
            tmp = matrix[i][j]
            matrix[i][j] = matrix[x][i]
            matrix[x][i] = matrix[y][x]
            matrix[y][x] = matrix[j][y]
            matrix[j][y] = tmp
