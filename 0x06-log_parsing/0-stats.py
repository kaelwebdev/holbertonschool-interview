#!/usr/bin/python3
"""
script that reads stdin line by line and computes metrics:
"""
import sys

if __name__ == "__main__":
    s_codes = {
        '200': 0,
        '301': 0,
        '400': 0,
        '401': 0,
        '403': 0,
        '404': 0,
        '405': 0,
        '500': 0,
    }

    f_size = 0
    c = 0

    def print_s_codes(codes, size):
        print('File size: {}'.format(size))
        for code, c in sorted(codes.items()):
            if c != 0:
                print('{}: {}'.format(code, c))

    try:
        for line in sys.stdin:
            c = c + 1
            input_array = line.split()
            try:
                f_size = int(f_size) + int(input_array[-1])
                code = input_array[-2]
                if code in s_codes:
                    s_codes[code] = s_codes[code] + 1
            except Exception:
                pass
            if c % 10 == 0:
                print_s_codes(s_codes, f_size)
        print_s_codes(s_codes, f_size)
    except KeyboardInterrupt:
        print_s_codes(s_codes, f_size)
        raise
