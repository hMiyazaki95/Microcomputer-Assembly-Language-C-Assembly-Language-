#include <stdio.h>
#include <string.h>
#include "cal.h"

void getDays(char *buffer, int mon, int year)
{
    // Use this pattern to help your write to the buffer:
    int char_out_count = 0;
    int First_day, Days_num, Days_week;
    
    
    First_day = getFirstDayOfMonth(mon, year);
    Days_num = getNumOfDaysInMonth(mon, year);
    
    for(int i = 0; i < First_day; i++){
        printf("   ");
    }
    
    for(int i = 1; i < Days_num + 1; i++){
        printf("%3d", i);
        
        if(i + First_day % 7 == 0) {
            printf("\n");
        }
        char_out_count += sprintf(buffer + char_out_count, "   ");
    }
    
}