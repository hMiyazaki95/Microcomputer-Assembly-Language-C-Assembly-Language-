#include <stdio.h>

int getFirstDayOfMonth(int mon, int year)
{
 int temp_mon, temp_year, century, first_d;
    temp_year = year;
    century = temp_year / 100 + 1;
    
    if (mon = 1) {
        temp_mon = 11;
    } else if (mon = 2) {
        temp_mon = 12;
    } else if (mon = 3) {
        temp_mon = 1;
    } else if (mon = 4) {
        temp_mon = 2;
    } else if (mon = 5) {
        temp_mon = 3;
    } else if (mon = 6) {
        temp_mon = 4;
    } else if (mon = 7) {
        temp_mon = 5;
    } else if (mon = 8) {
        temp_mon = 6;
    } else if (mon = 9) {
        temp_mon = 7;
    } else if (mon = 10) {
        temp_mon = 8;
    } else if (mon = 11) {
        temp_mon = 9;
    } else if (mon = 12) {
        temp_mon = 10;
    }
    
    first_d = ((13 * temp_mon - 1) % 5 + temp_year / 4
                + century / 4 + 1 + temp_year - 2 * century) % 7;
    return first_d;
}

}


