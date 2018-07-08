# inline comments look like this
"""Docstring comments look ike this"""


# add operation
def add(num1, num2):
    """Returns num1 plus num2"""
    return num1 + num2


# subtract operation
def subtract(num1, num2):
    return num1 - num2


# multiply operation
def multiply(num1, num2):
    return num1 * num2


# divide operation
def divide(num1, num2):
    try:
        return num1 / num2
    except ZeroDivisionError:  # catches division by 0 error
        print("Handled div by 0. Returning 0.")
        return 0


def run_operation(operation, num1, num2):
    """Determines the operation to run based on the operation
    argument which should be passed in as an int"""
    if operation == 1:
        print(add(num1, num2))
    elif operation == 2:
        print(subtract(num1, num2))
    elif operation == 3:
        print(multiply(num1, num2))
    elif operation == 4:
        print(divide(num1, num2))
    else:
        print("I don't understand")


def main():
    """Allows user to run basic calculator operations with two numbers"""

    # FOR LOOPS EXAMPLE
    # The following repeats a sequence of instructions for a specified number of times
    # for i in range(2):
    # In this case, it repeats the actions twice
    valid_input = False
    while not valid_input:
        # Get user input
        try:
            num1 = int(input("Enter num1: "))
            num2 = int(input("Enter num2: "))
            operation = int(input("What do you want to do? (1 = add, 2 = subtract, 3 = multiply, or 4 = divide):"))

            valid_input = True
        except ValueError:  # catches errors dealing with invalid input type
            print("Invalid input. Try again.")
        except:
            print("Unknown error")
    # Determine operation
    run_operation(operation, num1, num2)


main()
