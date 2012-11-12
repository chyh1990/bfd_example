CC=gcc

all: testcase bfd

bfd: bfd.o
	$(CC) -o $@ $^

testcase: testcase.o
	$(CC) -o $@ $^

.PHONY: test
test: all
	./bfd testcase
