CC=gcc
CFLAGS=-g -D__USE_FIXED_PROTOTYPES__ -ansi

all: pronounce_words pronounce_words2

pronounce_words: pronounce_words.c
	$(CC) $(CFLAGS) -o pronounce_words pronounce_words.c

pronounce_words2: pronounce_words2.c
	$(CC) $(CFLAGS) -o pronounce_words2 pronounce_words2.c

clean:
	rm -f pronounce_words pronounce_words2

