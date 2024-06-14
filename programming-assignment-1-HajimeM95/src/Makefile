
all: getFirstDayOfMonth.o getMonthYear.o getNumOfDaysInMonth.o getDays.o getDaysOfWeek.o isLeapYear.o

c_cal: getFirstDayOfMonth.o getMonthYear.o getNumOfDaysInMonth.o getDays.o getDaysOfWeek.o isLeapYear.o
	gcc -std=c99 -g -o ../out/c_cal cal.c ../out/getFirstDayOfMonth.o ../out/getMonthYear.o ../out/getNumOfDaysInMonth.o ../out/getDays.o ../out/getDaysOfWeek.o ../out/isLeapYear.o
	
%.o: %.c
	gcc -std=c99 -c -o ../out/$@ $<

# %: %.c
# 	gcc -std=c99 -g -o $@ $<

clean:
	-rm -f ../out/c_cal
	-rm -f ../out/*.o