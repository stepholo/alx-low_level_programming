#!/usr/bin/python3
""" Module to define function island_parameter
"""


def island_perimeter(grid):
    """Function to determine perimeter of an island

        Parameters:
            grind: list of list of integers
                    0 represents a water zone
                    1 represents a land zone
                    One cell is a square with side length 1
                    Grid cells are connected horizontally/vertically.
                    Grid is rectangular, width and height don’t exceed 100
        Return:
            The perimeter of the island within the grind
    """

    if type(grid) is not list:
        raise TypeError('grid has to be a list')
    elif len(grid) > 100:
        raise TypeError('grid width and height cannot exceed 100')
    else:
        j = 0
        for i in grid:
            if type(i) is not list:
                raise TypeError('grid has to be a list of list')
            elif type(i[j]) is not int:
                raise ValueError(
                        'grid has to be a list of list with only integers'
                        )
            elif len(i) > 100:
                raise TypeError('grid width and height cannot exceed 100')
            j += 1

    width = len(grid[0])
    height = len(grid)
    size = 0
    edge = 0
    for i in range(height):
        for j in range(width):
            if grid[i][j] == 1:
                size += 1
                if (j > 0 and grid[i][j-1] == 1):
                    edge += 1
                if (i > 0 and grid[i-1][j] == 1):
                    edge += 1
    return (size * 4) - (edge * 2)
