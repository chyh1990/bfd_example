CC=gcc
CFLAGS=-g

all: testcase bfd dwarf

bfd: bfd.o
	$(CC) -o $@ $^ -lbfd

testcase: testcase.o
	$(CC) -o $@ $^

dwarf: dwarfreader.o
	$(CC) -o $@ $^ -ldwarf -lelf

.PHONY: test clean
test: all
	./bfd testcase
	./dwarf testcase

clean:
	rm -f *.o testcase bfd
