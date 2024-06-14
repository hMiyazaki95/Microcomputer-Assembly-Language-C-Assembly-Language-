
int isLeapYear(int year)
{
    int leap_year = 0;
    if((year /100) % 4 == 0) {
        if(year % 100 / 4 == 0) {
            leap_year = 1;
        }
    }
    
    return leap_year;

}