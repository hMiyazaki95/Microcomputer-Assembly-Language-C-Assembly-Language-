#include <stdio.h>
#include <string.h>

void getMonthYear(char *buffer, char monday, int year)
{
    // TODO: complete this function
    #include <stdio.h>
#include <string.h>

void getMonthYear(char *buffer, int month_num, int year)
{
    
    if(month_num == 1) {
        sprintf(buffer, "January %d\n", year)
    } else if(month_num == 2) {
        sprintf(buffer, "February %d\n", year)
    } else if(month_num == 3) {
        sprintf(buffer, "March %d\n", year)
    } else if(month_num == 4) {
        sprintf(buffer, "April %d\n", year)
    } else if(month_num == 5) {
        sprintf(buffer, "May %d\n", year)
    } else if(month_num == 6) {
        sprintf(buffer, "June %d\n", year)
    } else if(month_num == 7) {
        sprintf(buffer, "July %d\n", year)
    } else if(month_num == 8) {
        sprintf(buffer, "August %d\n", year)
    } else if(month_num == 9) {
        sprintf(buffer, "September %d\n", year)
    } else if(month_num == 10) {
        sprintf(buffer, "October %d\n", year)
    } else if(month_num == 11) {
        sprintf(buffer, "Novenber %d\n", year)
    } else if(month_num == 12) {
        sprintf(buffer, "December %d\n", year)
    }
}
