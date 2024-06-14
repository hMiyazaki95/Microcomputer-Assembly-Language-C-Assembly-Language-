
/**
 * Prints the month and year as a title.
 */
void getMonthYear(char *buffer, int mon, int year);

/**
 * Prints Su - Sat.
 */
void getDaysOfWeek(char *buffer);

/**
 * Uses the Zeller algorithm to determine which the first day of the month.
 */
int getFirstDayOfMonth(int mon, int year);

/**
 * Gets the number of days in the given month.
 */
int getNumOfDaysInMonth(int mon, int year);

/**
 * Prints every day of the month.
 */
void getDays(char *buffer, int mon, int year);

/**
 * Returns whether the given year is a leap year.
 */
int isLeapYear(int year);
