// ************** TUTORIAL 04 **************
// In this tutorial we will be covering:
//  - If-Else Statements
//  - Switch Statements
//  - For Loops
//  - While Loops
//  - Do While Loops

/*  Conditional statements help you to make decisions based on certain conditions. These conditions are specified by a set of
    conditional statements having boolean expressins which are evaluated to a boolean value true or false. This evaluation
    often involves the use of relational and logical operators to make these checks. These operators return boolean values 
    (1 or TRUE, 0 or FALSE).
    
    RELATIONAL OPERATORS :
        == 	is equal to                             e.g. 5 == 5 is TRUE
        !=	is not equal to                         e.g. 5 != 7 is TRUE
        >	is greater than                         e.g. 7 > 5 is TRUE
        <	is less than                            e.g. 5 < 7 is TRUE
        >=	is greater than or equal to             e.g. 7 >= 5 is TRUE
        <=	is less than or equal to                e.g. 5 <= 5 is TRUE

    LOGICAL OPERATORS :
    (Assume A = 1, and B = 0)
        &&  - logical AND operator. If both the operands are non-zero, then the condition is true (e.g. A && B is FALSE)
        
        ||  - logical OR operator. If one of the operands is non-zero, then the condition is true (e.g. A || B is TRUE)

        !   - logical NOT operator. Used to reverse the logical state of its operand. (e.g. !(A && B) is TRUE)

    One of the most common types of conditional statements is if and else statements.

   +++++ IF-ELSE STATEMENTS +++++
---------------------------------------------------------------------------------------------------------------------------
    IF-ELSE STATEMENT FORMAT : 
    if (boolean_expression)
    {
        execute code if boolean expression is true
    }
    else if (boolean_expression)
    {
        execute code if boolean expression is true
    }
    else
    {
        default; execute if other expressions are false
    }
*/


#include <stdio.h>

int main() {
    unsigned int grade = 0;
    printf("Enter a grade : ");
    scanf("%u", &grade);

    // Braces are not needed if there is only one line of code in the 
    // body of the conditional statement
    if (grade >= 80)
        printf("Great job, you got an A!\n");
    // If not true, evaluate the next condition
    else if ((grade <= 79) && (grade >= 60))
        printf("Nice, a B!\n");
    else if ((grade <= 59) && (grade >= 50))
        printf("Ok, a C.\n");
    else // default statement
        printf("Aww, you failed.\n");

    return 0;
}

/* +++++ END IF-ELSE STATEMENTS +++++ */