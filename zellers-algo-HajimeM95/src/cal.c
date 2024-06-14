#include <stdio.h>
#include <string.h>
#include "cal.h"

int main()
{
    int mon = -1;
    int year = -1;

    printf("Month: ");
    scanf("%d", &mon);
    
    if (mon < 1 || mon > 12)
    {
        printf("Invalid month: %d! Must be between 1 and 12\n", mon);
        return 1;
    } 	

    printf("Year: ");
    scanf("%d", &year);

    if (year < 2000)
    {
        printf("Invalid year: %d! Must be 2000 or later!\n", year);
        return 1;
    }

    printf("\n");
    
    // Output buffer
    char buffer[4096];
    memset(buffer, 0, 4096);
    
    getMonthYear(buffer, mon, year);
    printf("%s", buffer);
    memset(buffer, 0, 4096);
    
    getDaysOfWeek(buffer);
    printf("%s", buffer);
    memset(buffer, 0, 4096);
    
    getDays(buffer, mon, year);
    printf("%s", buffer);
}