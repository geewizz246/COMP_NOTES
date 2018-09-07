// Program to find the LCM of two given integers
#include <iostream>

// Returns the lowest common multiple of two integers
int LCM(int n1, int n2);

int main() {
    int num1 = 7, num2 = 8;
    printf("LCM of %d and %d is %d\n", num1, num2, LCM(num1, num2));
    
    return 0;
}

int LCM(int n1, int n2)
{
    int max = n1 > n2 ? n1 : n2;
    
    do {
        if (max % n1 == 0 && max % n2 == 0)
        {
            return max;
            break;
        } else {
            max++;
        }
    } while (true);
}