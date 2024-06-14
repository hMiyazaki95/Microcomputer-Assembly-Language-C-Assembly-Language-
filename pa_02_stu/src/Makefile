
all: long_list.o istack.o iqueue.o linked_list.o queue_list.o

%.o: %.c
	gcc -std=c99 -c -o ../out/$@ $<


# %: %.c
# 	gcc -std=c99 -g -o $@ $<

clean:
	-rm -f ../out/*.o
