CFLAGS = -g -pedantic -std=c99 -Wall -Wextra
all: sort
sort: sort.c
	gcc $(CFLAGS) -o sort $^
clean:
	rm -rf sorts