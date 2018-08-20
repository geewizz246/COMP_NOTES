#include <stdio.h>
#include <stdlib.h>

int main()
{
    int pageViews = 0;
    
    printf("Page views : %d\n", pageViews);
    pageViews = pageViews + 1;
    printf("Page views : %d\n", pageViews);
    pageViews = pageViews + 1;
    printf("Page views : %d\n", pageViews);
    pageViews = pageViews + 1;
    printf("Page views : %d\n", pageViews);
    
    float balance = 1000.0;
    
    printf("Balance : %.2f\n", balance);
    balance *= 1.05; // Increase balance based on 5% interest
    printf("Balance : %.2f\n", balance);
    balance *= 1.05;
    printf("Balance : %.2f\n", balance);
    balance *= 1.05;
    printf("Balance : %.2f\n", balance);
    balance *= 1.05;
    printf("Balance : %.2f\n", balance);
    
    return 0;
}
