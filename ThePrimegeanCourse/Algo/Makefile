CC      = gcc
CFLAGS  = -g
RM      = rm -f


default: all

all: LinearSearchList  BinarySearch TwoCrystalBalls BubbleSort Queue

LinearSearchList: LinearSearchList.c
	$(CC) $(CFLAGS) -o LinearSearchList LinearSearchList.c

BinarySearch: BinarySearch.c
	$(CC) $(CFLAGS) -o  BinarySearch BinarySearch.c -lm

TwoCrystalBalls: TwoCrystalBalls.c
	$(CC) $(CFLAGS) -o TwoCrystalBalls TwoCrystalBalls.c -lm

BubbleSort: BubbleSort.c
	$(CC) $(CFLAGS) -o BubbleSort BubbleSort.c

Queue: Queue.c
	$(CC) $(CFLAGS) -o Queue Queue.c

clean veryclean:
	$(RM) LinearSearchList BinarySearch TwoCrystalBalls BubbleSort Queue
