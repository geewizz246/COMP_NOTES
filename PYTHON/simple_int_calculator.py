# inline comments look like this
"""Docstring comments look ike this"""


def add(num1, num2):
    """Returns num1 plus num2"""
    return num1 + num2


def subtract(num1, num2):
    return num1 - num2


def multiply(num1, num2):
    return num1 * num2


def divide(num1, num2):
    return num1 / num2


def main():
    num1 = int(input("Enter num1: "))
    num2 = int(input("Enter num2: "))
    add_result = add(num1, num2)
    subtract_result = subtract(num1, num2)
    multiply_result = multiply(num1, num2)
    divide_result = divide(num1, num2)
    print(add_result, subtract_result, multiply_result, divide_result)


main()
