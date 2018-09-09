/* +++++ FOR LOOPS +++++
---------------------------------------------------------------------------------------------------------------------------
    A for loop is a repitition control structure that allows you to efficiently write a loop that needs to execute a 
    specific number of times. For loops give the following functionality
        - Initialise the iterator variable using an initial value
        - Evaluate boolean condition. If true, the body of the loop is executed. If false, body of the loop does not 
          execute  and flow of control jumps to the next statement directly succeeding the for loop
        - In/decrease the iterator

        S
    FOR LOOP FORMAT :
    for (initialisation; boolean condition; in/decrement)
    {
        execute statement(s);
    }
*/

#include <stdio.h>

int main() {
    // Iterating on a code block 10 times
    int i;
    for (i = 0; i < 10; i++)
    {
        printf("%d\n", i);
    }

    // Using a for loop to access array values
    printf("\nArray : \n");
    int arr[10] = { 2, 4, 6, 8, 10, 12, 14, 16, 18, 20 };
    int sum = 0;
    for (i = 0; i < 10; i++)
    {
        printf("[%d]\t%d\n", i, arr[i]);
        sum += arr[i];
    }
   
    printf("Sum = %d\n", sum);

    return 0;
}