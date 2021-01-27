#!/usr/bin/python3
"""Script that reads stdin line by line and computes metrics"""

import sys

data = {'Size': 0, 'Codes': {200: 0, 301: 0, 400: 0, 401: 0,
                             403: 0, 404: 0, 405: 0, 500: 0}}


def printFormat():
    """Function that prints the file size and all the status codes"""

    print("File size: {}".format(data['Size']))

    for statusCode, count in sorted(data['Codes'].items()):
        if count != 0:
            print("{}: {}".format(statusCode, count))


def cleanDict(dict={}):
    """Function that sets all the elements of a dictionary to 0"""

    for elem in dict.keys():
        dict[elem] = 0


if __name__ == "__main__":

    try:

        lines = 1
        for line in sys.stdin:

            """Split the line taken from stdin and save only the needed data"""

            newLine = line.split(" ")
            code = int(newLine[-2])
            size = int(newLine[-1][:-1])

            """If the status code is a possible status code
            it will count + 1 in the dict to count how many of they are"""

            if code in data['Codes']:
                data['Codes'][code] += 1

            data['Size'] += size
            lines += 1

            if lines % 10 == 0:
                printFormat()

                """Cleaning up everything to next iteration"""
                cleanDict(data['Codes'])

    except KeyboardInterrupt:
        """Handling CTRL + C"""
        printFormat()
        raise

    printFormat()
