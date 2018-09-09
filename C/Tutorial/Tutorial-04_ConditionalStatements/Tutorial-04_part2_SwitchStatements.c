/* +++++ SWITCH STATEMENTS +++++
---------------------------------------------------------------------------------------------------------------------------
    Feeling lazy so look at these two sites for an explanation:
        - https://www.geeksforgeeks.org/switch-statement-cc/
        - https://www.tutorialspoint.com/cprogramming/switch_statement_in_c.htm


    SWITCH STATEMENT FORMAT :
    switch (expression) {
        case constant_expression :
            execute statement(s);
            break; // Optional; if omitted, execution will go through all subsequent cases until a break is reached

        case constant_expression :
            execute statement(s);
            break;

        // You can have any number of case statements
        default : // Optional; must appear at the end of the switch; performed when none of the cases are true
            execute statement(s);
            // No break is needed in the default statement
    }
*/

#include <stdio.h>

int main() {
    char grade;
    printf("Enter a grade : ");
    scanf("%c", &grade);

    switch (grade) {
        case 'A' :
            printf("Great job, you got an A!\n");
            break;
        
        case 'B' :
            printf("Nice, a B!\n");
            break;
        
        case 'C' :
            printf("Okay, a C.\n");
            break;
        
        default :
            printf("Aww, you failed.\n");
    }

    return 0;
}

/* +++++ END SWITCH STATEMENTS +++++ */