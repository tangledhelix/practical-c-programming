CC=gcc
CFLAGS=-g -D__USE_FIXED_PROTOTYPES__ -ansi

all: word_counter word_counter2

word_counter: word_counter.c
	$(CC) $(CFLAGS) -o word_counter word_counter.c

word_counter2: word_counter2.c
	$(CC) $(CFLAGS) -o word_counter2 word_counter2.c

clean:
	rm -f word_counter word_counter2

