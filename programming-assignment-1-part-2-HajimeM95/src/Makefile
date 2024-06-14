
all: getFirstDayOfMonth.o getMonthYear.o getNumOfDaysInMonth.o getDays.o getDaysOfWeek.o isLeapYear.o

x86_cal: getFirstDayOfMonth.o getMonthYear.o getNumOfDaysInMonth.o getDays.o getDaysOfWeek.o isLeapYear.o
	gcc -std=c99 -g -o ../out/x86_cal cal.c ../out/getFirstDayOfMonth.o ../out/getMonthYear.o ../out/getNumOfDaysInMonth.o ../out/getDays.o ../out/getDaysOfWeek.o ../out/isLeapYear.o
	
%.o: %.s
	gcc -std=c99 -c -o ../out/$@ $<

clean:
	-rm -f ../out/x86_cal
	-rm -f ../out/*.o