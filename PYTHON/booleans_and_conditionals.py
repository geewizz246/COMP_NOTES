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
    """Allows user to run basic calculator operations on two numbers"""
    num1 = int(input("Enter num1: "))
    num2 = int(input("Enter num2: "))
    operation = int(input("What do you want to do? (add, subtract, multiply, or divide):"))

    if operation == 1:
        print(add(num1, num2))
    elif operation == 'subtract':
        print(subtract(num1, num2))
    elif operation == 'multiply':
        print(multiply(num1, num2))
    elif operation == 'divide':
        print(divide(num1, num2))
    else:
        print("I don't understand")


main()
