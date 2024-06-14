
x86_cal: cal.c getDays.s getFirstDayOfMonth.s
	gcc -std=c99 -no-pie -g -o ../out/x86_cal cal.c getDays.s getFirstDayOfMonth.s ../out/*.o
	
%.o: %.c
	gcc -std=c99 -c -o ../out/$@ $<

# %: %.c
# 	gcc -std=c99 -g -o $@ $<

clean:
	-rm -f ../out/x86_cal
