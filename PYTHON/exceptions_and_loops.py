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
    return num1 / num2


def main():
    """Allows user to run basic calculator operations with two numbers"""
    user_continue = True

    # Repeat until the user no longer wants to continue
    while user_continue:
        valid_input = False
        while not valid_input:
            # Get user input
            try:
                num1 = int(input("Enter num1: "))
                num2 = int(input("Enter num2: "))
                operation = int(input("What do you want to do? (1 = add, 2 = subtract, 3 = multiply, or 4 = divide):"))
                valid_input = True
            except:
                print("Invalid input. Try again.")

        # Determine operation
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

        # Ask user to continue
        user_yn = input("Do you want to continue doing more calculations? (y = yes, anything else to exit)")
        if user_yn != 'y':
            user_continue = False
        else:
            continue


main()
