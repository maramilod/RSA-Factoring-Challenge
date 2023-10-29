#!/usr/bin/python3
import sys
"""
h
e
y
"""


def read_numbers_from_file(filename):
    """
    d
    """
    try:
        with open(filename, 'r') as file:
            numbers = [int(line.strip()) for line in file.readlines()]
        return numbers
    except Exception as e:
        print(f"Error reading file: {str(e)}")
        return []


def gcd(a, b):
    """
    g
    """
    while b != 0:
        a, b = b, a % b
    return a


def pollards_rho(n):
    """
    p
    """
    if n % 2 == 0:
        return 2
    x = 2
    y = 2
    d = 1

    def f(x):
        return (x**2 + 1) % n

    while d == 1:
        x = f(x)
        y = f(f(y))
        d = gcd(abs(x-y), n)
    return d


def factorize_numbers():
    """
    f
    """
    if len(sys.argv) < 2:
        print("Usage: factors <file>")
        return
    filename = sys.argv[1]
    numbers = read_numbers_from_file(filename)
    if not numbers:
        print("No numbers to factorize")
        return
    try:
        for n in numbers:
            p = pollards_rho(n)
            q = n // p
            print(f"{n}={q}*{p}")
    except Exception as e:
        print(f"An error occurred: {str(e)}")

if __name__ == "__main__":
    factorize_numbers()
